#include <iostream>

#include "BoundedQueue.hpp"
#include "ConcurrentQueue.hpp"
#include "LWBoundedQueue.hpp"

void exampleBoundedQueue() {
  std::cout << "Example BoundedQueue" << std::endl;

  DogBreeds::Labrador::BoundedQueue<int> intBoundedQueue(10);

  DogBreeds::Labrador::AbstractQueue<int>& queueWrapperInt = intBoundedQueue;
  for (int i = 0; i < 10; i++) {
    queueWrapperInt.enqueue(i + 1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << "Dequeued:" << queueWrapperInt.dequeue() << std::endl;
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
  }
}

// void exampleLWBoundedQueue() {
//   std::cout << "Example LWBoundedQueue" << std::endl;

//   DogBreeds::Labrador::LWBoundedQueue<int> intBoundedQueue(10);

//   DogBreeds::Labrador::AbstractQueue<int>& queueWrapperInt = intBoundedQueue;
//   for (int i = 0; i < 10; i++) {
//     queueWrapperInt.enqueue(i + 1);
//     std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
//   }

//   for (int i = 0; i < 10; i++) {
//     std::cout << "Dequeued:" << queueWrapperInt.dequeue() << std::endl;
//     std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
//   }
// }

void exampleConcurrentQueue() {
  std::cout << "Example ConcurrentQueue" << std::endl;

  DogBreeds::Labrador::ConcurrentQueue<int> intConcurrentQueue;

  DogBreeds::Labrador::AbstractQueue<int>& queueWrapperInt = intConcurrentQueue;

  for (int i = 0; i < 11; i++) {
    queueWrapperInt.enqueue(i + 1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
  }

  for (int i = 0; i < 11; i++) {
    std::cout << "Dequeued:" << queueWrapperInt.dequeue() << std::endl;
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
  }
}

int main() {
  exampleBoundedQueue();
  exampleConcurrentQueue();
}
