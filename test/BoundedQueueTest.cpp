#include <gtest/gtest.h>
#include "BoundedQueue.hpp"
#include <thread>

using namespace DogBreeds::Labrador;

// Test per verificare che la coda sia inizialmente vuota
TEST(BoundedQueueTest, InitiallyEmpty)
{
    BoundedQueue<int> queue(5);
    ASSERT_EQ(queue.size(), 0);
}

// Test per verificare l'inserimento e il recupero di un elemento dalla coda
TEST(BoundedQueueTest, EnqueueDequeue)
{
    BoundedQueue<int> queue(5);
    queue.enqueue(10);
    ASSERT_EQ(queue.size(), 1);
    ASSERT_EQ(queue.dequeue(), 10);
    ASSERT_EQ(queue.size(), 0);
}

// Test per verificare che il lancio di un'eccezione avvenga quando si prova a recuperare da una coda vuota
TEST(BoundedQueueTest, DequeueEmptyQueue)
{
    BoundedQueue<int> queue(5);
    ASSERT_THROW(queue.dequeue(), std::runtime_error);
}

// Test per verificare che la coda si riempia correttamente fino alla sua capacità massima
TEST(BoundedQueueTest, FillToCapacity)
{
    BoundedQueue<int> queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    ASSERT_EQ(queue.size(), 3);
    ASSERT_THROW(queue.enqueue(4), std::runtime_error); // Tentativo di inserire un elemento quando la coda è piena
}

// Test per verificare che il tentativo di inserire in una coda piena blocchi correttamente
TEST(BoundedQueueTest, EnqueueBlockedWhenFull)
{
    BoundedQueue<int> queue(2);
    queue.enqueue(1);
    queue.enqueue(2);
    std::thread t([&queue]() {
        ASSERT_THROW(queue.enqueue(3), std::runtime_error); // Tentativo di inserire un elemento quando la coda è piena
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Attendi un breve periodo per assicurarti che il thread t sia in attesa
    ASSERT_EQ(queue.size(), 2);
    t.join();
}

// Test per verificare che il recupero da una coda vuota blocchi correttamente
TEST(BoundedQueueTest, DequeueBlockedWhenEmpty)
{
    BoundedQueue<int> queue(3);
    std::thread t([&queue]() {
        ASSERT_THROW(queue.dequeue(), std::runtime_error); // Tentativo di recuperare un elemento quando la coda è vuota
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Attendi un breve periodo per assicurarti che il thread t sia in attesa
    ASSERT_EQ(queue.size(), 0);
    t.join();
}

// Test per verificare che la coda funzioni correttamente con più thread
TEST(BoundedQueueTest, ConcurrentAccess)
{
    BoundedQueue<int> queue(5);
    constexpr int num_elements = 1000;
    std::thread producer([&queue]() {
        for (int i = 0; i < num_elements; ++i){
            bool inserted = false;
            while(!inserted){
                inserted = true;
                try{
                    queue.enqueue(i);
                }catch(std::runtime_error){
                    inserted=false;
                }
            }
        }
    });
    std::thread consumer([&queue]() {
        for (int i = 0; i < num_elements; ++i)
            ASSERT_EQ(queue.dequeue(), i);
    });
    producer.join();
    consumer.join();
    ASSERT_EQ(queue.size(), 0);
}
