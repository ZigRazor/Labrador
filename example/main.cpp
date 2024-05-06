#include <iostream>
#include "BoundedQueue.hpp"

int main(){
    std::cout << "Example BoundedQueue" << std::endl;

    DogBreeds::Labrador::BoundedQueue<int> intBoundedQueue(10);
    intBoundedQueue.push(1);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(2);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(3);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(4);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(5);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(6);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(7);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(8);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(9);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(10);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
    intBoundedQueue.push(11);
    std::cout << "Queue Size" << intBoundedQueue.size() << std::endl;
}