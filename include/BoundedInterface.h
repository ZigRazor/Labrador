#ifndef DOGBREEDS_LABRADOR_BOUNDEDINTERFACE_H
#define DOGBREEDS_LABRADOR_BOUNDEDINTERFACE_H

#include <cstddef>

namespace DogBreeds{
    namespace Labrador{
        class BoundedInterface{
            protected:
                size_t  m_maxSize;
            public:
                BoundedInterface(size_t  maxSize);
                virtual ~BoundedInterface() = default;
               
                virtual size_t getMaxSize() const;
                virtual void setMaxSize(size_t  maxSize);
        };

    }
}

#endif //DOGBREEDS_LABRADOR_BOUNDEDINTERFACE_H