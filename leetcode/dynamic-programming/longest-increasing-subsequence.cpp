//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Longest Increasing Subsequence
 *
 * The Longest Increasing Subsequence (LIS) problem is to find the length
 * of the longest subsequence of a given sequence such that all elements
 * of the subsequence are sorted in increasing order. For example, the
 * length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is
 * {10, 22, 33, 50, 60, 80}.
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * Example:
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * Note:
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // 首先来看一种动态规划Dynamic Programming的解法，这种解法的时间复杂度为O(n2)，类似brute force的解法，
  // 我们维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，对于每一个nums[i]，我们从第一个数再搜索到i，
  // 如果发现某个数小于nums[i]，我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，
  // 即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，我们就这样不断的更新dp数组，
  // 到最后dp数组中最大的值就是我们要返回的LIS的长度
  static int lengthOfLIS_dp(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
      res = std::max(res, dp[i]);
    }
    return res;
  }
  // O(nlogn)
  // 使用一个二分查找的方式，找到递增子数组中大于等于当前值的第一个数的位置；
  // 如果找到，则利用当前值替换；否则将当前值加入到递增子数组中，表明该值比子数组的值都大，可能输入子数组。
  // 例子：nums = [5,6,7,1,2,8,3,4,0,5,9]：
  // 遍历到 7: res = [5,6,7]；
  // 遍历到 2: res = [1,2,7];
  // 遍历到 8: res = [1,2,7,8];
  // 遍历到 3: res = [1,2,3,8];
  // 遍历到 4: res = [1,2,3,4];
  // 剩下三个元素 : res = [0,2,3,4,5,9];
  // 最后我们就可以得到最长递增子序列的长度，但是这里要注意得到的子序列不是真正的子序列，然而其长度是正确的。
  // 该算法无法得到最长递增子序列，仅计算长度
  static int lengthOfLIS(std::vector<int> &nums) {
    if (nums.size() <= 0) return 0;
    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
      if (it == res.end())
        res.push_back(nums[i]);
      else
        *it = nums[i];
    }

    return res.size();
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec_1{10, 22, 9, 33, 21, 50, 41, 60, 80};
  std::vector<int> vec_2{10, 9, 2, 5, 3, 7, 101, 18};
  if (Solution::lengthOfLIS_dp(vec_1) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::lengthOfLIS_dp(vec_2) != 4) {
    throw std::runtime_error("error 2");
  }
  if (Solution::lengthOfLIS(vec_1) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::lengthOfLIS(vec_2) != 4) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
