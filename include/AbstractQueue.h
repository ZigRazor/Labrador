/**
 * @file AbstractQueue.h
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief An Abstract Class for Queue
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H
#define DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H

#include <cstddef>
namespace DogBreeds {
namespace Labrador {

/**
 * @brief Abstract Queue Class
 *
 * @tparam T the Type of the queue
 */
template <typename T>
class AbstractQueue {
 public:
  /**
   * @brief Enqueue the item
   *
   * @param item the item to enqueue
   */
  virtual void enqueue(const T &item) = 0;
  /**
   * @brief Dequeue an item from queue
   *
   * @return T the item dequeued
   */
  virtual T dequeue() = 0;
  /**
   * @brief Return the size of the queue
   *
   * @return size_t the size of the queue
   */
  virtual size_t size() const = 0;
  /**
   * @brief Check if the queue is empty
   *
   * @return true if the queue is empty
   * @return false otherways
   */
  virtual bool isEmpty() const { return size() == 0; }

  /**
   * @brief Destroy the Abstract Queue object
   *
   */
  virtual ~AbstractQueue() {}
};

}  // namespace Labrador
}  // namespace DogBreeds

#endif  // DOGBREEDS_LABRADOR_ABSTRACTQUEUE_H