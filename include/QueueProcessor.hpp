#ifndef DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H
#define DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H

#include <functional>
#include <memory>
#include <thread>
#include "AbstractQueue.h"

namespace DogBreeds
{
    namespace Labrador
    {

        template <typename T>
        class QueueProcessor
        {
        private:
            std::shared_ptr<AbstractQueue<T>> queue;
            std::function<void(T &)> elaborationFunction;
            bool stopRequested;
            std::thread processingThread;

        public:
            QueueProcessor(std::shared_ptr<AbstractQueue<T>> q, std::function<void(T &)> elaborationFunc)
                : queue(q), elaborationFunction(elaborationFunc), stopRequested(false)
            {
                processingThread = std::thread(&QueueProcessor::processQueue, this);
            }

            ~QueueProcessor()
            {
                stop();
                if (processingThread.joinable())
                {
                    processingThread.join();
                }
            }

            void stop()
            {
                stopRequested = true;
            }

        private:
            void processQueue()
            {
                while (!stopRequested)
                {
                    try
                    {
                        T item = queue->dequeue();
                        elaborationFunction(item);
                    }
                    catch (const std::runtime_error &e)
                    {
                        // Handle the exception when the queue is empty
                        //std::cerr << "Caught exception: " << e.what() << std::endl;
                        // Optionally, you can wait or perform other actions before retrying
                        std::this_thread::sleep_for(std::chrono::microseconds(10));
                    }
                }
            }
        };
    }
}

#endif // DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H