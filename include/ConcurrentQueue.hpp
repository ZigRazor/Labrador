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
                ConcurrentQueue():ConcurrentInterface() {}

                virtual ~ConcurrentQueue() = default;

                ConcurrentQueue(const ConccurentQueue&) = delete;

                T front() override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    return m_queue.front();
                }

                T back() override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    return m_queue.back();
                }

                void pop() override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    m_queue.pop();
                }

                void push (const T& val) override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    m_queue.push(val);
                }
                
                void push (T&& val) override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    m_queue.push(val);
                }

                bool empty() const override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    return m_queue.empty();
                }

                size_t size() const override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    return m_queue.size();
                }

                template <class... Args> void emplace (Args&&... args){
                    std::lock_guard<std::mutex> lock(m_mutex);
                    m_queue.emplace(args...);
                }

                void swap (SyncQueue& x) {
                    std::lock_guard<std::mutex> lock(m_mutex);
                    std::lock_guard<std::mutex> lockX(x.m_mutex);
                    this.m_queue.swap(x.m_queue);
                }


        };

    }
}

#endif //DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H