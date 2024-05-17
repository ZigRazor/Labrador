#include <gtest/gtest.h>

#include <atomic>
#include <thread>

#include "LWBoundedQueue.hpp"

using namespace DogBreeds::Labrador;

// Test per verificare che la coda sia inizialmente vuota
TEST(LWBoundedQueueTest, InitiallyEmpty) {
  LWBoundedQueue<int> queue(5);
  ASSERT_EQ(queue.size(), 0);
}

// Test per verificare l'inserimento e il recupero di un elemento dalla coda
TEST(LWBoundedQueueTest, EnqueueDequeue) {
  LWBoundedQueue<int> queue(5);
  queue.enqueue(10);
  ASSERT_EQ(queue.size(), 1);
  ASSERT_EQ(queue.dequeue(), 10);
  ASSERT_EQ(queue.size(), 0);
}

/*
// Test per verificare che il recupero da una coda vuota blocchi correttamente
TEST(LWBoundedQueueTest, DequeueEmptyQueue)
{
    LWBoundedQueue<int> queue(3);
    std::atomic<bool> dequeueStarted(false);
    std::atomic<bool> dequeueSuccessful(false);

    std::thread t([&queue, &dequeueStarted, &dequeueSuccessful]() {
        dequeueStarted = true;
        try {
            queue.dequeue();
            dequeueSuccessful = true;
        } catch (const std::runtime_error &) {
            // Il recupero non è riuscito
        }
    });

    // Attendiamo che il thread di dequeue inizi l'esecuzione
    while (!dequeueStarted)
        std::this_thread::yield();

    // Attendiamo un breve periodo di tempo per assicurarci che il thread sia
bloccato std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Verifichiamo se il thread di dequeue è ancora in esecuzione
    ASSERT_FALSE(dequeueSuccessful);

    // Terminiamo il thread di dequeue
    //t.~thread();
    //if (t.joinable()) t.join();

    ASSERT_EQ(queue.size(), 0);
}
*/
// Test per verificare che la coda si riempia correttamente fino alla sua
// capacità massima
TEST(LWBoundedQueueTest, FillToCapacity) {
  LWBoundedQueue<int> queue(3);
  constexpr int num_elements = 3;
  std::atomic<bool> enqueueFinished(false);

  std::thread producer([&queue, &enqueueFinished]() {
    for (int i = 0; i < num_elements; ++i) queue.enqueue(i);
    enqueueFinished = true;
  });
  // Attendiamo un massimo di 500 ms per il completamento dell'inserimento
  producer.joinable()
      ? producer.join()
      : std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  ASSERT_TRUE(
      enqueueFinished);  // Verifichiamo se l'inserimento è stato completato

  // Verifichiamo che la coda sia piena
  ASSERT_EQ(queue.size(), num_elements);
}
/*
// Test per verificare che il recupero da una coda vuota blocchi correttamente
TEST(LWBoundedQueueTest, DequeueBlockedWhenEmpty)
{
    LWBoundedQueue<int> queue(3);
    std::thread t([&queue]() {
        ASSERT_THROW(queue.dequeue(), std::runtime_error); // Tentativo di
recuperare un elemento quando la coda è vuota
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Attendi un
breve periodo per assicurarti che il thread t sia in attesa

    t.~thread();
    ASSERT_EQ(queue.size(), 0);

}
*/
// Test per verificare che la coda funzioni correttamente con più thread
TEST(LWBoundedQueueTest, ConcurrentAccess) {
  LWBoundedQueue<int> queue(5);
  constexpr int num_elements = 1000;
  std::thread producer([&queue]() {
    for (int i = 0; i < num_elements; ++i) queue.enqueue(i);
  });
  std::thread consumer([&queue]() {
    for (int i = 0; i < num_elements; ++i) ASSERT_EQ(queue.dequeue(), i);
  });
  producer.join();
  consumer.join();
  ASSERT_EQ(queue.size(), 0);
}