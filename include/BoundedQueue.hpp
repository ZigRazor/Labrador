#ifndef DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H

#include "QueueWrapperInterface.h"
#include "BoundedInterface.h"
#include <queue>

namespace DogBreeds{
    namespace Labrador{
        
        template<typename T>
        class BoundedQueue : public QueueWrapperInterface<T>, public BoundedInterface{
            public:
                BoundedQueue(size_t  maxSize):BoundedInterface(maxSize) {}

                virtual ~BoundedQueue() = default;

                BoundedQueue(const BoundedQueue&) = delete;

                 T dequeue() override{
                    auto& elem =  this->m_queue.front();
                    this->m_queue.pop();
                    return elem;
                }

                void enqueue (const T& val) override{
                    if(this->m_queue.size() < this->m_maxSize){
                        this->m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }
                
                void enqueue (T&& val) override{
                    if(this->m_queue.size() < this->m_maxSize){
                        this->m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }

                bool empty() override{
                    return this->m_queue.empty();
                }

                size_t size() override{
                    return this->m_queue.size();
                }

                void setMaxSize(size_t  maxSize) override{
                    if(maxSize < this->m_queue.size()){
                        //TODO return error
                    }else{
                        this->m_maxSize = maxSize;
                    }
                }


        };

    }
}

#endif //DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H