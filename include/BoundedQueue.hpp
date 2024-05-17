#ifndef DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H
#define DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

#include "AbstractQueue.h"

namespace DogBreeds {
namespace Labrador {

template <typename T>
class BoundedQueue : public AbstractQueue<T> {
 private:
  std::queue<T> queue;
  mutable std::mutex mtx;
  std::condition_variable enq_cv;
  std::condition_variable deq_cv;
  size_t max_size;

 public:
  BoundedQueue(size_t size) : max_size(size) {}

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

  size_t size() const override {
    std::lock_guard<std::mutex> lock(mtx);
    return queue.size();
  }
};

}  // namespace Labrador
}  // namespace DogBreeds

#endif  // DOGBREEDS_LABRADOR_BOUNDEDQUEUE_H