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

                virtual T dequeue() = 0;

                virtual void enqueue (const T& val) = 0;
                
                virtual void enqueue (T&& val) = 0;

                virtual bool empty() = 0;

                virtual size_t size() = 0;

        };

    }
}

#endif //DOGBREEDS_LABRADOR_QUEUEWRAPPERINTERFACE_H