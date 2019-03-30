//
// Created by Lu, Chih-chiang on 2019-02-06.
//

#include <stdexcept>

class Queue {
 public:
  Queue(int capacity) : arr_(new int[capacity]), rear_(capacity - 1), size_(0), front_(0), capacity_(capacity) {}

  // Queue is full when size becomes equal to the capacity
  bool isFull() {
    return size_ == capacity_;
  }

  // Queue is empty when size is 0
  bool isEmpty() {
    return size_ == 0;
  }

  // Method to add an item to the queue.
  // It changes rear and size
  void enqueue(int item) {
    if (isFull()) {
      return;
    }
    rear_ = (rear_ + 1) % capacity_;
    arr_[rear_] = item;
    ++size_;
  }

  // Method to remove an item from queue.
  // It changes front and size
  int dequeue() {
    if (isEmpty()) {
      throw std::runtime_error("dequeue(): Queue is empty");
    }
    int item = arr_[front_];
    front_ = (front_ + 1) % capacity_;
    --size_;
    return item;
  }

  int front() {
    if (isEmpty()) {
      throw std::runtime_error("front(): Queue is empty");
    }
    return arr_[front_];
  }

  int rear() {
    if (isEmpty()) {
      throw std::runtime_error("rear(): Queue is empty");
    }
    return arr_[rear_];
  }

 private:
  int *arr_;
  int rear_;
  int size_;
  int front_;
  int capacity_;
};

int main(int argc, char *argv[]) {
  Queue q(5);
  if (!q.isEmpty()) {
    throw std::runtime_error("error 1");
  }
  q.enqueue(9);
  q.enqueue(8);
  q.enqueue(7);
  q.enqueue(6);
  q.enqueue(5);
  if (!q.isFull()) {
    throw std::runtime_error("error 2");
  }
  if (q.front() != 9 || q.rear() != 5 || q.dequeue() != 9) {
    throw std::runtime_error("error 3");
  }
  if (q.front() != 8 || q.rear() != 5 || q.dequeue() != 8) {
    throw std::runtime_error("error 4");
  }
  if (q.front() != 7 || q.rear() != 5 || q.dequeue() != 7) {
    throw std::runtime_error("error 5");
  }
  if (q.front() != 6 || q.rear() != 5 || q.dequeue() != 6) {
    throw std::runtime_error("error 6");
  }
  if (q.front() != 5 || q.rear() != 5 || q.dequeue() != 5) {
    throw std::runtime_error("error 7");
  }
  if (!q.isEmpty()) {
    throw std::runtime_error("error 8");
  }

  return 0;
}
