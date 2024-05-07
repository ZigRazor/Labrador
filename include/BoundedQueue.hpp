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

                T front() override{
                    return m_queue.front();
                }

                T back() override{
                    return m_queue.back();
                }

                void pop() override{
                    m_queue.pop();
                }

                void push (const T& val) override{
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }
                
                void push (T&& val) override{
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }

                bool empty() const override{
                    return m_queue.empty();
                }

                size_t size() const override{
                    return m_queue.size();
                }

                template <class... Args> void emplace (Args&&... args){
                    m_queue.emplace(args...);
                }

                void swap (BoundedQueue& x) {
                    if(x.m_queue.size() <= this.m_maxSize && this.m_queue.size() <= x.m_maxSize){
                        this.m_queue.swap(x.m_queue);
                    }else{
                        //TODO return error
                    }
                }

                void setMaxSize(size_t  maxSize) override{
                    if(maxSize < m_queue.size()){
                        //TODO return error
                    }else{
                        m_maxSize = maxSize;
                    }
                }


        };

    }
}

#endif //DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H