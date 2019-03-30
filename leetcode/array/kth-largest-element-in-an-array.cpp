//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Kth Largest Element in an Array
 *
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <queue>
#include <vector>

class Solution {
 public:
  static int findKthLargest_v1(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }

  static int findKthLargest_v2(std::vector<int> &nums, int k) {
    std::priority_queue<int> queue(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
      queue.pop();
    }
    return queue.top();
  }

  // quick sort
  static int partition(std::vector<int> &nums, int left, int right) {
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r) {
      if (nums[l] < pivot && nums[r] > pivot) {
        std::swap(nums[l++], nums[r--]);
      }
      if (nums[l] >= pivot) ++l;
      if (nums[r] <= pivot) --r;
    }
    std::swap(nums[left], nums[r]);
    return r;
  }
  static int findKthLargest(std::vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (true) {
      int pos = partition(nums, l, r);
      if (pos == k - 1) {
        return nums[pos];
      } else if (pos > k - 1) {
        r = pos - 1;
      } else {
        l = pos + 1;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {3, 2, 1, 5, 6, 4};
  std::vector<int> vec2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  if (Solution::findKthLargest(vec1, 2) != 5) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findKthLargest(vec2, 4) != 4) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
