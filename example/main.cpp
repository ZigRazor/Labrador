#include <iostream>
#include "BoundedQueue.hpp"
#include "ConcurrentQueue.hpp"
#include "ConcurrentBoundedQueue.hpp"


void exampleBoundedQueue(){
     std::cout << "Example BoundedQueue" << std::endl;

    DogBreeds::Labrador::BoundedQueue<int> intBoundedQueue(10);

    DogBreeds::Labrador::QueueWrapperInterface<int>&  queueWrapperInt = intBoundedQueue;
    queueWrapperInt.enqueue(1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(2);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(3);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(4);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(5);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(6);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(7);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(8);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(9);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(10);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(11);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
}

void exampleConcurrentQueue(){
     std::cout << "Example ConcurrentQueue" << std::endl;

    DogBreeds::Labrador::ConcurrentQueue<int> intConcurrentQueue;

    DogBreeds::Labrador::QueueWrapperInterface<int>&  queueWrapperInt = intConcurrentQueue;
    queueWrapperInt.enqueue(1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(2);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(3);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(4);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(5);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(6);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(7);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(8);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(9);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(10);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(11);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;

}

void exampleConcurrentBoundedQueue(){
     std::cout << "Example ConcurrentBoundedQueue" << std::endl;

    DogBreeds::Labrador::ConcurrentBoundedQueue<int> intConcurrentBoundedQueue(10);

    DogBreeds::Labrador::QueueWrapperInterface<int>&  queueWrapperInt = intConcurrentBoundedQueue;
    queueWrapperInt.enqueue(1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(2);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(3);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(4);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(5);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(6);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(7);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(8);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(9);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(10);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.enqueue(11);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;

}

int main(){
   exampleBoundedQueue();
   exampleConcurrentQueue();
   exampleConcurrentBoundedQueue();
}
