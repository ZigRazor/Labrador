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

                ConcurrentBoundedQueue(const ConcurrentBoundedQueue&) = delete;

                T dequeue() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    auto& elem = this->m_queue.front();
                    this->m_queue.pop();
                    return elem;
                }

                void enqueue (const T& val) override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    if(this->m_queue.size() < this->m_maxSize){
                        this->m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }
                
                void enqueue (T&& val) override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    if(this->m_queue.size() < this->m_maxSize){
                        this->m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }

                bool empty() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    return this->m_queue.empty();
                }

                size_t size() override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    return this->m_queue.size();
                }

                void setMaxSize(size_t  maxSize) override{
                    std::lock_guard<std::mutex> lock(this->m_mutex);
                    if(maxSize < this->m_queue.size()){
                        //TODO return error
                    }else{
                        this->m_maxSize = maxSize;
                    }
                }


        };

    }
}

#endif //DOGBREEDS_LABRADOR_CONCURRENTBOUNDEDQUEUE_H