//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Kth Largest Element in a Stream
 *
 * Design a class to find the kth largest element in a stream.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts an integer k and an integer array nums,
 * which contains initial elements from the stream. For each call to the method KthLargest.add,
 * return the element representing the kth largest element in the stream.
 *
 * Example:
 *
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 *
 * Note:
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class KthLargest {
 public:
  KthLargest(int k, std::vector<int> nums) {
    k_ = k;
    for (auto num : nums) {
      min_heap_.push(num);
    }
    while (min_heap_.size() > k_) {
      min_heap_.pop();
    }
  }

  int add(int val) {
    min_heap_.push(val);
    if (min_heap_.size() > k_) {
      min_heap_.pop();
    }
    return min_heap_.top();
  }
 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;
  int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

int main(int argc, char *argv[]) {
  KthLargest *obj = new KthLargest(3, {4, 5, 8, 2});
  if (obj->add(3) != 4) {
    throw std::runtime_error("error 1");
  }
  if (obj->add(5) != 5) {
    throw std::runtime_error("error 2");
  }
  if (obj->add(10) != 5) {
    throw std::runtime_error("error 3");
  }
  if (obj->add(9) != 8) {
    throw std::runtime_error("error 4");
  }
  if (obj->add(4) != 8) {
    throw std::runtime_error("error 5");
  }
  return 0;
}
