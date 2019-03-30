//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Range Addition
 *
 * Assume you have an array of length n initialized with all 0's and are given k update operations.
 *
 * Each operation is represented as a triplet: [startIndex, endIndex, inc]
 * which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
 *
 * Return the modified array after all k operations were executed.
 *
 * Example:
 *
 * Given:
 *
 *     length = 5,
 *     updates = [
 *         [1,  3,  2],
 *         [2,  4,  3],
 *         [0,  2, -2]
 *     ]
 *
 * Output:
 *
 *     [-2, 0, 3, 5, 3]
 * Explanation:
 *
 * Initial state:
 * [ 0, 0, 0, 0, 0 ]
 *
 * After applying operation [1, 3, 2]:
 * [ 0, 2, 2, 2, 0 ]
 *
 * After applying operation [2, 4, 3]:
 * [ 0, 2, 5, 5, 3 ]
 *
 * After applying operation [0, 2, -2]:
 * [-2, 0, 3, 5, 3 ]
 */

#include <vector>
#include <stdexcept>

// 这道题的提示说了我们肯定不能把范围内的所有数字都更新，而是只更新开头结尾两个数字就行了，
// 那么我们的做法就是在开头坐标startIndex位置加上inc，而在结束位置加1的地方加上-inc，那么根据题目中的例子，
// 我们可以得到一个数组，nums = {-2, 2, 3, 2, -2, -3}，然后我们发现对其做累加和就是我们要求的结果result = {-2, 0, 3, 5, 3}
class Solution {
 public:
  static std::vector<int> getModifiedArray(int length, std::vector<std::vector<int>> &updates) {
    std::vector<int> res(length, 0);

    for (auto &update : updates) {
      res[update[0]] += update[2];
      if (update[1] + 1 < length) {
        res[update[1] + 1] -= update[2];
      }
    }
    for (int i = 1; i < length; ++i) {
      res[i] += res[i - 1];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
  std::vector<int> out = {-2, 0, 3, 5, 3};
  if (Solution::getModifiedArray(5, vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
