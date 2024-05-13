#include <iostream>
#include "QueueProcessor.hpp"
#include "BoundedQueue.hpp"
#include "LWBoundedQueue.hpp"
#include "ConcurrentQueue.hpp"

void elabFunc(int &value)
{
    std::cout << "Dequeued:" << value << std::endl;
}

void exampleBoundedQueue()
{
    std::cout << "Example BoundedQueue Processor" << std::endl;

    auto intBoundedQueue = std::make_shared<DogBreeds::Labrador::BoundedQueue<int>>(10);

    DogBreeds::Labrador::QueueProcessor<int> qp(intBoundedQueue, elabFunc);

    std::shared_ptr<DogBreeds::Labrador::AbstractQueue<int>> queueWrapperInt = intBoundedQueue;
    for (int i = 0; i < 10000; i++)
    {
        queueWrapperInt->enqueue(i + 1);
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
    }

    while(!queueWrapperInt->isEmpty()){
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void exampleLWBoundedQueue()
{
    std::cout << "Example LWBoundedQueue Processor" << std::endl;

    auto intBoundedQueue = std::make_shared<DogBreeds::Labrador::LWBoundedQueue<int>>(10);

    DogBreeds::Labrador::QueueProcessor<int> qp(intBoundedQueue, elabFunc);

    std::shared_ptr<DogBreeds::Labrador::AbstractQueue<int>> queueWrapperInt = intBoundedQueue;
    for (int i = 0; i < 10000; i++)
    {
        queueWrapperInt->enqueue(i + 1);
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
    }

    while(!queueWrapperInt->isEmpty()){
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void exampleConcurrentQueue()
{
    std::cout << "Example ConcurrentQueue Processor" << std::endl;

    auto intConcurrentQueue = std::make_shared<DogBreeds::Labrador::ConcurrentQueue<int>>();

    DogBreeds::Labrador::QueueProcessor<int> qp(intConcurrentQueue, elabFunc);

    std::shared_ptr<DogBreeds::Labrador::AbstractQueue<int>> queueWrapperInt = intConcurrentQueue;
    for (int i = 0; i < 10000; i++)
    {
        queueWrapperInt->enqueue(i + 1);
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
    }
    while(!queueWrapperInt->isEmpty()){
        std::cout << "Queue Size" << queueWrapperInt->size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    exampleBoundedQueue();
    exampleConcurrentQueue();
}
