#include "ConcurrentInterface.h"

namespace DogBreeds{
    namespace Labrador{

        std::mutex& ConcurrentInterface::getMutex(){
            return m_mutex;
        }

        std::condition_variable& ConcurrentInterface::getConditionVariable(){
            return m_cv;
        }
    }
}
