//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int findKth(std::vector<int> nums1, std::vector<int> nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
      return findKth(nums2, nums1, k);
    } else if (m == 0) {
      return nums2[k - 1];
    } else if (k == 1) {
      return std::min(nums1[0], nums2[0]);
    }

    int part1 = std::min(k / 2, m);
    int part2 = k - part1;

    if (nums1[part1 - 1] == nums2[part2 - 1]) {
      return nums1[part1 - 1];
    } else if (nums1[part1 - 1] < nums2[part2 - 1]) {
      return findKth(std::vector<int>(nums1.begin() + part1, nums1.end()), nums2, k - part1);
    } else {
      return findKth(nums1, std::vector<int>(nums2.begin() + part2, nums2.end()), k - part2);
    }
  }
  static double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size(), k = (m + n) / 2;

    if ((m + n) % 2 == 0) {
      return (findKth(nums1, nums2, k) + findKth(nums1, nums2, k + 1)) / 2.0;
    } else {
      return findKth(nums1, nums2, k + 1);
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 3};
  std::vector<int> vec2 = {2};
  std::vector<int> vec3 = {1, 2};
  std::vector<int> vec4 = {3, 4};
  if (Solution::findMedianSortedArrays(vec1, vec2) != 2.0) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findMedianSortedArrays(vec3, vec4) != 2.5) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
