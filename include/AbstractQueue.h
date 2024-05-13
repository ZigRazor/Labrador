#ifndef DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H
#define DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H

namespace DogBreeds
{
    namespace Labrador
    {

        template <typename T>
        class AbstractQueue
        {
        public:
            virtual void enqueue(const T &item) = 0;
            virtual T dequeue() = 0;
            virtual size_t size() const = 0;
            virtual bool isEmpty() const
            {
                return size() == 0;
            }

            virtual ~AbstractQueue() {}
        };

    }
}

#endif // DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H