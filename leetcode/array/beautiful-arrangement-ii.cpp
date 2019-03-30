//
// Created by Lu, Chih-chiang on 2018-12-16.
//

/**
 * Beautiful Arrangement II
 *
 * Given two integers n and k, you need to construct a list which contains n different positive integers
 * ranging from 1 to n and obeys the following requirement:
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]
 * has exactly k distinct integers.
 *
 * If there are multiple answers, print any of them.
 *
 * Example 1:
 *
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 *
 * Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1]
 * has exactly 1 distinct integer: 1.
 *
 * Example 2:
 *
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 *
 * Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1]
 * has exactly 2 distinct integers: 1 and 2.
 *
 * Note:
 * The n and k are in the range 1 <= k < n <= 10^4.
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> constructArray(int n, int k) {
    std::vector<int> res;
    int i = 1, j = n;
    while (i <= j) {
      res.push_back(k > 1 ? (k-- % 2 ? i++ : j--) : i++);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> out = {1, 2, 3};
  if (Solution::constructArray(3, 1) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
