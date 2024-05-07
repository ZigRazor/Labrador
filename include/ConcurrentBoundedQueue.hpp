#ifndef DOGBREEDS_LABRADOR_CONCURRENTBOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_CONCURRENTBOUNDEDQUEUE_H

#include "QueueWrapperInterface.h"
#include "BoundedInterface.h"
#include "ConcurrentInterface.h"
#include <queue>

namespace DogBreeds{
    namespace Labrador{
        
        template<typename T>
        class ConcurrentBoundedQueue : public QueueWrapperInterface<T>, public ConcurrentInterface,  public BoundedInterface{
            public:
                ConcurrentBoundedQueue(size_t  maxSize):ConcurrentInterface(),BoundedInterface(maxSize) {}

                virtual ~ConcurrentBoundedQueue() = default;

                ConcurrentBoundedQueue(const BoundedQueue&) = delete;

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
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }
                
                void push (T&& val) override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
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

                void swap (SyncBoundedQueue& x) {
                    std::lock_guard<std::mutex> lock(m_mutex);
                    std::lock_guard<std::mutex> lock(x.m_mutex);
                    if(x.m_queue.size() <= this.m_maxSize && this.m_queue.size() <= x.m_maxSize){
                        this.m_queue.swap(x.m_queue);
                    }else{
                        //TODO return error
                    }
                }

                void setMaxSize(size_t  maxSize) override{
                    std::lock_guard<std::mutex> lock(m_mutex);
                    if(maxSize < m_queue.size()){
                        //TODO return error
                    }else{
                        m_maxSize = maxSize;
                    }
                }


        };

    }
}

#endif //DOGBREEDS_LABRADOR_CONCURRENTBOUNDEDQUEUE_H