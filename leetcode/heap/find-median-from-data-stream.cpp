//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Find Median from Data Stream
 *
 * Median is the middle value in an ordered integer list.
 * If the size of the list is even, there is no middle value.
 * So the median is the mean of the two middle value.
 *
 * For example,
 * [2,3,4], the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Design a data structure that supports the following two operations:
 *
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far.
 *
 * Example:
 *
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3)
 * findMedian() -> 2
 */

#include <queue>
#include <stdexcept>

// max_heap keeps smaller values
// min_heap keeps bigger values
class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    max_heap_.push(num);
    // exchange to make sure min_heap owns bigger value / max_heap owns smaller value
    min_heap_.push(max_heap_.top());
    max_heap_.pop();

    // balance size
    if (max_heap_.size() < min_heap_.size()) {
      max_heap_.push(min_heap_.top());
      min_heap_.pop();
    }
  }

  double findMedian() {
    return max_heap_.size() > min_heap_.size() ? (double) max_heap_.top() : (max_heap_.top() + min_heap_.top()) * 0.5;
  }
 private:
  std::priority_queue<long, std::vector<long>, std::greater<long>> min_heap_;
  std::priority_queue<long> max_heap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main(int argc, char *argv[]) {
  MedianFinder *obj = new MedianFinder();
  obj->addNum(1);
  if (obj->findMedian() != 1.0) {
    throw std::runtime_error("error 1");
  }
  obj->addNum(2);
  if (obj->findMedian() != 1.5) {
    throw std::runtime_error("error 2");
  }
  obj->addNum(3);
  if (obj->findMedian() != 2.0) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
