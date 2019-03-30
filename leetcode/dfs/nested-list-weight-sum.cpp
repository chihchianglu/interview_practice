//
// Created by Lu, Chih-chiang on 2019-03-11.
//

/**
 * Nested List Weight Sum
 *
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 *
 * Input: [[1,1],2,[1,1]]
 * Output: 10
 * Explanation: Four 1's at depth 2, one 2 at depth 1.
 *
 * Example 2:
 *
 * Input: [1,[4,[6]]]
 * Output: 27
 * Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
 */

#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer,
  // rather than a nested list.
  bool isInteger() const {
    return false;
  }

  // Return the single integer that this NestedInteger holds,
  // if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const {
    return 0;
  }

  // Return the nested list that this NestedInteger holds,
  // if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const std::vector<NestedInteger> &getList() const {
    return list_;
  }
 private:
  std::vector<NestedInteger> list_;
};

class Solution {
 public:
  int depthSum(std::vector<NestedInteger> &nestedList) {
    return helper(nestedList, 1);
  }
  int helper(const std::vector<NestedInteger> &nl, int depth) {
    int res = 0;
    for (auto a : nl) {
      res += a.isInteger() ? a.getInteger() * depth : helper(a.getList(), depth + 1);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
