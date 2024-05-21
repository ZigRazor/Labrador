/**
 * @file QueueProcessor.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief Queue Processor
 * @version 0.1
 * @date 2024-05-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H
#define DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H

#include <functional>
#include <memory>
#include <thread>

#include "AbstractQueue.h"

namespace DogBreeds {
namespace Labrador {
/**
 * @brief Queue Processor Class
 *
 * @tparam T queue element type
 */
template <typename T>
class QueueProcessor {
 private:
  /**
   * @brief the queue to process
   *
   */
  std::shared_ptr<AbstractQueue<T>> queue;
  /**
   * @brief the elaboration function to process queue's elements
   *
   */
  std::function<void(T &)> elaborationFunction;
  /**
   * @brief boolean value to stop the process
   *
   */
  bool stopRequested;
  /**
   * @brief the dequeue processing thread
   *
   */
  std::thread processingThread;

 public:
  /**
   * @brief Construct a new Queue Processor object
   *
   * @param q the queue to process
   * @param elaborationFunc the function to process queue's elements
   */
  QueueProcessor(std::shared_ptr<AbstractQueue<T>> q,
                 std::function<void(T &)> elaborationFunc)
      : queue(q), elaborationFunction(elaborationFunc), stopRequested(false) {
    processingThread = std::thread(&QueueProcessor::processQueue, this);
  }
  /**
   * @brief Destroy the Queue Processor object
   *
   */
  ~QueueProcessor() {
    stop();
    if (processingThread.joinable()) {
      processingThread.join();
    }
  }
  /**
   * @brief stop the process
   *
   */
  void stop() { stopRequested = true; }

 private:
  /**
   * @brief Queue process function
   *
   */
  void processQueue() {
    while (!stopRequested) {
      try {
        T item = queue->dequeue();
        elaborationFunction(item);
      } catch (const std::runtime_error &e) {
        // Handle the exception when the queue is empty
        // std::cerr << "Caught exception: " << e.what() << std::endl;
        // Optionally, you can wait or perform other actions before retrying
        std::this_thread::sleep_for(std::chrono::microseconds(10));
      }
    }
  }
};
}  // namespace Labrador
}  // namespace DogBreeds

#endif  // DOGBREEDS_LABRADOR_QUEUEPROCESSOR_H