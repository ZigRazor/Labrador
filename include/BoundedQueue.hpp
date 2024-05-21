/**
 * @file BoundedQueue.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief A Bounded Queue
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

#include "AbstractQueue.h"
namespace DogBreeds {
namespace Labrador {
/**
 * @brief Bounded Queue Class
 *
 * @tparam T the type of the Bounded Queue
 */
template <typename T>
class BoundedQueue : public AbstractQueue<T> {
 private:
  /**
   * @brief The internal queue
   *
   */
  std::queue<T> queue;
  /**
   * @brief mutex for the internal queue operation
   *
   */
  mutable std::mutex mtx;
  /**
   * @brief Condition Variable for Enqueue
   *
   */
  std::condition_variable enq_cv;
  /**
   * @brief Condition Variable for Dequeue
   *
   */
  std::condition_variable deq_cv;
  /**
   * @brief Max Size of the queue
   *
   */
  size_t max_size;

 public:
  /**
   * @brief Construct a new Bounded Queue object
   *
   * @param size the max size of the bounded queue
   */
  BoundedQueue(size_t size) : max_size(size) {}

  /**
   * {@inheritDoc}
   */
  void enqueue(const T &item) override {
    {
      std::unique_lock<std::mutex> lock(mtx);
      enq_cv.wait_for(lock, std::chrono::microseconds(10),
                      [this]() { return queue.size() < max_size; });
      if (queue.size() < max_size) {
        queue.push(item);
      } else {
        throw std::runtime_error("Queue is full");
      }
    }
    deq_cv.notify_one();  // Notify waiting dequeue operations
  }

  /**
   * {@inheritDoc}
   */
  T dequeue() override {
    T item;
    {
      std::unique_lock<std::mutex> lock(mtx);
      deq_cv.wait_for(lock, std::chrono::microseconds(10),
                      [this]() { return !queue.empty(); });
      if (!queue.empty()) {
        item = queue.front();
        queue.pop();
      } else {
        throw std::runtime_error("Queue is empty");
      }
    }
    enq_cv.notify_one();  // Notify waiting enqueue operations
    return item;
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

#endif  // DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H