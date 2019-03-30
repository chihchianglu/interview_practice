//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * Moving Average from Data Stream
 *
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 *
 * For example,
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 */

#include <queue>
#include <stdexcept>

class MovingAverage {
 public:
  MovingAverage(int size) : size_(size), sum_(0) {}

  double next(int val) {
    if (queue_.size() >= size_) {
      sum_ -= queue_.front();
      queue_.pop();
    }
    queue_.push(val);
    sum_ += val;
    return sum_ / queue_.size();
  }

 private:
  int size_;
  double sum_;
  std::queue<int> queue_;
};

int main(int argc, char *argv[]) {
  MovingAverage *ma = new MovingAverage(3);
  if (ma->next(1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (ma->next(10) != double(1 + 10) / 2) {
    throw std::runtime_error("error 1");
  }
  if (ma->next(3) != double(1 + 10 + 3) / 3) {
    throw std::runtime_error("error 1");
  }
  if (ma->next(5) != double(10 + 3 + 5) / 3) {
    throw std::runtime_error("error 1");
  }
  return 0;
}
