/**
 * @file ConcurrentQueue.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief A Concurrent Queue
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H
#define DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H

#include <mutex>
#include <queue>

#include "AbstractQueue.h"

namespace DogBreeds {
namespace Labrador {
/**
 * @brief Concurrent Queue Class
 *
 * @tparam T the type of the Queue
 */
template <typename T>
class ConcurrentQueue : public AbstractQueue<T> {
 private:
  /**
   * @brief The internal Queue
   *
   */
  std::queue<T> queue;
  /**
   * @brief The mutex for the internal queue
   *
   */
  mutable std::mutex mtx;

 public:
  /**
   * {@inheritDoc}
   */
  void enqueue(const T &item) override {
    std::lock_guard<std::mutex> lock(mtx);
    queue.push(item);
  }
  /**
   * {@inheritDoc}
   */
  T dequeue() override {
    std::lock_guard<std::mutex> lock(mtx);
    if (queue.empty()) {
      throw std::runtime_error("Queue is empty");
    }
    T item = queue.front();
    queue.pop();
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

#endif  // DOGBREEDS_LABRADOR_CONCURRENTQUEUE_H