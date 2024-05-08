#ifndef DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H
#define DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H

#include "QueueWrapperInterface.h"
#include "ConcurrentInterface.h"
#include <queue>

namespace DogBreeds{
    namespace Labrador{
        
        template<typename T>
        class ConcurrentQueue : public QueueWrapperInterface<T>, public ConcurrentInterface{
            public:
                ConcurrentQueue():QueueWrapperInterface<T>(),ConcurrentInterface() {}

                virtual ~ConcurrentQueue() = default;

                ConcurrentQueue(const ConcurrentQueue&) = delete;

                T dequeue() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    auto& elem = this->m_queue.front();
                    this->m_queue.pop();
                    return elem;
                }

                void enqueue (const T& val) override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    this->m_queue.push(val);
                }
                
                void enqueue (T&& val) override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    this->m_queue.push(val);
                }

                bool empty() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    return this->m_queue.empty();
                }

                size_t size() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    return this->m_queue.size();
                }

        };

    }
}

#endif //DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H