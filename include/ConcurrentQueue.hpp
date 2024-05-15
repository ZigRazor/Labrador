#ifndef DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H
#define DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H

#include <queue>
#include <mutex>
#include "AbstractQueue.h"

namespace DogBreeds
{
    namespace Labrador
    {
        template <typename T>
        class ConcurrentQueue : public AbstractQueue<T>
        {
        private:
            std::queue<T> queue;
            mutable std::mutex mtx;

        public:
            void enqueue(const T &item) override
            {
                std::lock_guard<std::mutex> lock(mtx);
                queue.push(item);
            }

            T dequeue() override
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (queue.empty())
                {
                    throw std::runtime_error("Queue is empty");
                }
                T item = queue.front();
                queue.pop();
                return item;
            }

            size_t size() const override{
                std::lock_guard<std::mutex> lock(mtx);
                return queue.size();
            }

        };

    }
}

#endif // DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H