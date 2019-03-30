//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Merge Sorted Array
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 *
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from
 * nums2.
 * Example:
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }

    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> vec2 = {2, 5, 6};
  std::vector<int> out = {1, 2, 2, 3, 5, 6};
  Solution::merge(vec1, 3, vec2, 3);
  if (vec1 != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
