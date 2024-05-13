#ifndef DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "AbstractQueue.h"

namespace DogBreeds
{
    namespace Labrador
    {

        template <typename T>
        class LWBoundedQueue : public AbstractQueue<T>
        {
        private:
            std::queue<T> queue;
            mutable std::mutex mtx;
            std::condition_variable enq_cv;
            std::condition_variable deq_cv;
            size_t max_size;

        public:
            LWBoundedQueue(size_t size) : max_size(size) {}

            void enqueue(const T &item) override
            {
                {
                    std::unique_lock<std::mutex> lock(mtx);
                    enq_cv.wait(lock, [this]()
                                { return queue.size() < max_size; });
                    queue.push(item);
                }
                deq_cv.notify_one(); // Notify waiting dequeue operations
            }

            T dequeue() override
            {
                {
                    while (true)
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        deq_cv.wait_for(lock, std::chrono::microseconds(10), [this]()
                                        { return !queue.empty(); });
                        if (!queue.empty())
                        {
                            T item = queue.front();
                            queue.pop();
                            enq_cv.notify_one(); // Notify waiting enqueue operations
                            return item;
                        }
                    }
                }
            }

            size_t size() const override
            {
                std::lock_guard<std::mutex> lock(mtx);
                return queue.size();
            }
        };

    }
}

#endif // DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H