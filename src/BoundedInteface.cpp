#include "BoundedInterface.h"

namespace DogBreeds
{
    namespace Labrador
    {
        BoundedInterface::BoundedInterface(size_t maxSize)
        {
            m_maxSize = maxSize;
        }

        size_t BoundedInterface::getMaxSize() const
        {
            return m_maxSize;
        }

        void BoundedInterface::setMaxSize(size_t maxSize)
        {
            m_maxSize = maxSize;
        }
    }
}