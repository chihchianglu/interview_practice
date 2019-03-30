//
// Created by Lu, Chih-chiang on 2019-03-11.
//

/**
 * Nested List Weight Sum II
 *
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Different from the previous question where weight is increasing from root to leaf, now the weight is defined from
 * bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 *
 * Example 1:
 *
 * Input: [[1,1],2,[1,1]]
 * Output: 8
 * Explanation: Four 1's at depth 1, one 2 at depth 2.
 *
 * Example 2:
 *
 * Input: [1,[4,[6]]]
 * Output: 17
 * Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
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
  int depthSumInverse(std::vector<NestedInteger> &nestedList) {
    int unweighted = 0, weighted = 0;
    while (!nestedList.empty()) {
      std::vector<NestedInteger> nextLevel;
      for (auto a : nestedList) {
        if (a.isInteger()) {
          unweighted += a.getInteger();
        } else {
          nextLevel.insert(nextLevel.end(), a.getList().begin(), a.getList().end());
        }
      }
      weighted += unweighted;
      nestedList = nextLevel;
    }
    return weighted;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
