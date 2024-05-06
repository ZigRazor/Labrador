#include <iostream>
#include "BoundedQueue.hpp"

int main(){
    std::cout << "Example BoundedQueue" << std::endl;

    DogBreeds::Labrador::BoundedQueue<int> intBoundedQueue(10);

    DogBreeds::Labrador::QueueWrapperInterface<int>&  queueWrapperInt = intBoundedQueue;
    queueWrapperInt.push(1);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(2);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(3);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(4);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(5);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(6);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(7);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(8);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(9);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(10);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
    queueWrapperInt.push(11);
    std::cout << "Queue Size" << queueWrapperInt.size() << std::endl;
}