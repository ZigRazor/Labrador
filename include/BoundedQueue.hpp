#ifndef DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H

#include "QueueWrapperInterface.h"
#include <queue>

namespace DogBreeds{
    namespace Labrador{
        
        template<typename T>
        class BoundedQueue : public QueueWrapperInterface<T>{
            private:
                std::queue<T> m_queue;
                size_t  m_maxSize;
            public:
                BoundedQueue(size_t  maxSize):m_queue(), m_maxSize(maxSize) {}

                virtual ~BoundedQueue() = default;

                T& front(){
                    return m_queue.front();
                }

                const T& front() const{
                    return m_queue.front();
                }

                T& back(){
                    return m_queue.back();
                }

                const T& back() const{
                    return m_queue.back();
                }


                void pop(){
                    m_queue.pop();
                }

                void push (const T& val){
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }
                
                void push (T&& val){
                    if(m_queue.size() < m_maxSize){
                        m_queue.push(val);
                    }else{
                        //TODO return error
                    }
                }

                bool empty() const{
                    return m_queue.empty();
                }

                size_t size() const{
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


        };

    }
}

#endif //DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H