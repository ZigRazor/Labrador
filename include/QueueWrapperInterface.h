#ifndef DOGBREEDS_LABRADOR_QUEUEWRAPPERINTERFACE_H
#define DOGBREEDS_LABRADOR_QUEUEWRAPPERINTERFACE_H

#include <queue>

namespace DogBreeds{
    namespace Labrador{
        
        template<typename T>
        class QueueWrapperInterface{
            protected:
                std::queue<T> m_queue;
            public:
                virtual T front() = 0;

                virtual T back() = 0;

                virtual void pop() = 0;

                virtual void push (const T& val) = 0;
                
                virtual void push (T&& val) = 0;

                virtual bool empty() const = 0;

                virtual size_t size() const = 0;

        };

    }
}

#endif //DOGBREEDS_LABRADOR_QUEUEWRAPPERINTERFACE_H