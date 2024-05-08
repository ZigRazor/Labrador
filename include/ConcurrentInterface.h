#ifndef DOGBREEDS_LABRADOR_CONCURRENTINTERFACE_H
#define DOGBREEDS_LABRADOR_CONCURRENTINTERFACE_H

#include <mutex>
#include <condition_variable>

namespace DogBreeds{
    namespace Labrador{
        class ConcurrentInterface{
            protected:
                std::mutex  m_mutex;
            public:
                ConcurrentInterface() = default;
                virtual ~ConcurrentInterface() = default;

                std::mutex& getMutex();


        };

    }
}

#endif //DOGBREEDS_LABRADOR_CONCURRENTINTERFACE_H