/**
 * @file LWBoundedQueue.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief A Lock-Wait Bounded Queue
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

#include "AbstractQueue.h"

namespace DogBreeds {
namespace Labrador {
/**
 * @brief Lock-Wait Bounded Queue
 *
 * @tparam T the type of the Queue
 */
template <typename T>
class LWBoundedQueue : public AbstractQueue<T> {
 private:
  /**
   * @brief the internal queue
   *
   */
  std::queue<T> queue;
  /**
   * @brief the mutex for the internal queue
   *
   */
  mutable std::mutex mtx;
  /**
   * @brief the condition variable for enqueue
   *
   */
  std::condition_variable enq_cv;
  /**
   * @brief the condition variable for dequeue
   *
   */
  std::condition_variable deq_cv;
  /**
   * @brief the max size for the queue
   *
   */
  size_t max_size;

 public:
  /**
   * @brief Construct a new LWBoundedQueue object
   *
   * @param size the max size of the queue
   */
  LWBoundedQueue(size_t size) : max_size(size) {}

  /**
   * {@inheritDoc}
   */
  void enqueue(const T &item) override {
    {
      std::unique_lock<std::mutex> lock(mtx);
      enq_cv.wait(lock, [this]() { return queue.size() < max_size; });
      queue.push(item);
    }
    deq_cv.notify_one();  // Notify waiting dequeue operations
  }

  /**
   * {@inheritDoc}
   */
  T dequeue() override {
    {
      while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        deq_cv.wait_for(lock, std::chrono::microseconds(10),
                        [this]() { return !queue.empty(); });
        if (!queue.empty()) {
          T item = queue.front();
          queue.pop();
          return item;
        }
        enq_cv.notify_one();  // Notify waiting enqueue operations
      }
    }
  }

  /**
   * {@inheritDoc}
   */
  size_t size() const override {
    std::lock_guard<std::mutex> lock(mtx);
    return queue.size();
  }
};

}  // namespace Labrador
}  // namespace DogBreeds

#endif  // DOGBREEDS_LABRADOR_LWBOUNDEDQUEUE_H