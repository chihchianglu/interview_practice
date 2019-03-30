//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Search in Rotated Sorted Array
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 */

#include <vector>
#include <stdexcept>

// 这道题让在旋转数组中搜索一个给定值，若存在返回坐标，若不存在返回-1。我们还是考虑二分搜索法，但是这道题的难点在于我们不知道原数组在哪旋转了，
// 我们还是用题目中给的例子来分析，对于数组[0 1 2 4 5 6 7] 共有下列七种旋转方法：
// 0124567
// 7 0 1 2 4 5 6
// 6 7 0 1 2 4 5
// 5 6 7 0 1 2 4
// 4 5 6 7 0 1 2
// 2 4 5 6 7 0 1
// 1 2 4 5 6 7 0
// 二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，我们观察上面红色的数字都是升序的，由此我们可以观察出规律，
// 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
// 我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
class Solution {
 public:
  static int search(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < nums[r]) {
        if (nums[mid] < target && nums[r] >= target) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else {
        if (nums[mid] > target && nums[l] <= target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
  if (Solution::search(vec, 0) != 4) {
    throw std::runtime_error("error 1");
  }
  if (Solution::search(vec, 3) != -1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
