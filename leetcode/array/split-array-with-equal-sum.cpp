//
// Created by Lu, Chih-chiang on 2019-01-05.
//

/**
 * Split Array with Equal Sum
 *
 * Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies
 * following conditions:
 *
 * 0 < i, i + 1 < j, j + 1 < k < n - 1
 *
 * Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
 * where we define that subarray (L, R) represents a slice of the original array starting from the element
 * indexed L to the element indexed R.
 *
 * Example:
 *
 * Input: [1,2,1,2,1,2,1]
 * Output: True
 *
 * Explanation:
 *
 * i = 1, j = 3, k = 5.
 * sum(0, i - 1) = sum(0, 0) = 1
 * sum(i + 1, j - 1) = sum(2, 2) = 1
 * sum(j + 1, k - 1) = sum(4, 4) = 1
 * sum(k + 1, n - 1) = sum(6, 6) = 1
 *
 * Note:
 * 1 <= n <= 2000.
 * Elements in the given array will be in range [-1,000,000, 1,000,000].
 */

// skip

#include <vector>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  static bool splitArray(std::vector<int> &nums) {
    int n = nums.size();
    if (n < 7) {
      return false;
    }
    std::vector<int> sums = nums;
    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + sums[i];
    }

    // Here j is used for middle cut, i for left cut and k for right cut.
    // Iterate middle cuts and then find left cuts which divides the first
    // half into two equal quarters, store that quarter sums in the hashset.
    // Then find right cuts which divides the second half into two equal
    // quarters and check if quarter sum is present in the hashset.
    // If yes return true.
    for (int j = 3; j < n - 3; ++j) {
      std::unordered_set<int> set;
      for (int i = 1; i < j - 1; ++i) {
        if (sums[i - 1] == sums[j - 1] - sums[i]) {
          set.insert(sums[i - 1]);
        }
      }
      for (int k = j + 2; k < n - 1; ++k) {
        int sum3 = sums[k - 1] - sums[j], sum4 = sums[n - 1] - sums[k];
        if (sum3 == sum4 && set.find(sum3) != set.end()) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 1, 2, 1, 2, 1};
  if (!Solution::splitArray(vec)) {
    throw std::runtime_error("error");
  }
  return 0;
}
