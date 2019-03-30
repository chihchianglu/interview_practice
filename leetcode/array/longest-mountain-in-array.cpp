//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Longest Mountain in Array
 *
 * Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
 *
 * B.length >= 3
 * There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 * (Note that B could be any subarray of A, including the entire array A.)
 *
 * Given an array A of integers, return the length of the longest mountain.
 *
 * Return 0 if there is no mountain.
 *
 * Example 1:
 *
 * Input: [2,1,4,7,3,2,5]
 * Output: 5
 *
 * Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 *
 * Example 2:
 *
 * Input: [2,2,2]
 * Output: 0
 *
 * Explanation: There is no mountain.
 *
 * Note:
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 *
 * Follow up:
 *
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 */

#include <vector>

class Solution {
 public:
  static int longestMountain_dp(std::vector<int> &A) {
    std::vector<int> inc(A.size());
    std::vector<int> dec(A.size());
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) {
        inc[i] = inc[i - 1] + 1;
      }
    }
    for (int i = A.size() - 2; i > 0; --i) {
      if (A[i] > A[i + 1]) {
        dec[i] = dec[i + 1] + 1;
      }
    }
    int res = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (inc[i] && dec[i]) {
        res = std::max(res, inc[i] + dec[i] + 1);
      }
    }
    return res >= 3 ? res : 0;
  }

  static int longestMountain(std::vector<int> &A) {
    int inc = 0, dec = 0, res = 0;
    for (int i = 1; i < A.size(); ++i) {
      if ((dec && A[i] > A[i - 1]) || (A[i] == A[i - 1])) {
        inc = dec = 0;
      }
      inc += A[i] > A[i - 1];
      dec += A[i] < A[i - 1];
      if (inc && dec) {
        res = std::max(res, inc + dec + 1);
      }
    }
    return res >= 3 ? res : 0;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 1, 4, 7, 3, 2, 5};
  std::vector<int> vec2 = {2, 2, 2};
  if (Solution::longestMountain_dp(vec1) != 5) {
    throw std::runtime_error("error 1");
  }
  if (Solution::longestMountain_dp(vec2) != 0) {
    throw std::runtime_error("error 2");
  }
  if (Solution::longestMountain(vec1) != 5) {
    throw std::runtime_error("error 3");
  }
  if (Solution::longestMountain(vec2) != 0) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
