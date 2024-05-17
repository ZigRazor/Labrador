#include <gtest/gtest.h>

#include <atomic>
#include <thread>

#include "ConcurrentQueue.hpp"

using namespace DogBreeds::Labrador;

// Test per verificare che la coda sia inizialmente vuota
TEST(ConcurrentQueueTest, InitiallyEmpty) {
  ConcurrentQueue<int> queue;
  ASSERT_EQ(queue.size(), 0);
}

// Test per verificare l'inserimento e il recupero di un elemento dalla coda
TEST(ConcurrentQueueTest, EnqueueDequeue) {
  ConcurrentQueue<int> queue;
  queue.enqueue(10);
  ASSERT_EQ(queue.size(), 1);
  ASSERT_EQ(queue.dequeue(), 10);
  ASSERT_EQ(queue.size(), 0);
}

// Test per verificare che il lancio di un'eccezione avvenga quando si prova a
// recuperare da una coda vuota
TEST(ConcurrentQueueTest, DequeueEmptyQueue) {
  ConcurrentQueue<int> queue;
  ASSERT_THROW(queue.dequeue(), std::runtime_error);
}

// Test per verificare che la coda funzioni correttamente con più thread
TEST(ConcurrentQueueTest, ConcurrentAccess) {
  ConcurrentQueue<int> queue;
  constexpr int num_elements = 1000;

  std::atomic<int> counter(
      0);  // Contatore atomico per tenere traccia degli elementi inseriti

  std::thread producer([&queue, &counter]() {
    for (int i = 0; i < num_elements; ++i) {
      queue.enqueue(i);
      counter++;
    }
  });

  std::thread consumer([&queue, &counter]() {
    while (counter < num_elements)
      ;  // Attendere finché tutti gli elementi non sono stati inseriti
    for (int i = 0; i < num_elements; ++i) {
      ASSERT_EQ(queue.dequeue(), i);
    }
  });

  producer.join();
  consumer.join();
  ASSERT_EQ(queue.size(), 0);
}