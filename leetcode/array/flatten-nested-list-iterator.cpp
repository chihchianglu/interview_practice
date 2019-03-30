//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * Flatten Nested List Iterator
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 *
 * Example 2:
 * Given the list [1,[4,[6]]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>
#include <vector>
#include <iostream>

class NestedInteger {
 public:
  bool isInteger() const { return true; }
  int getInteger() const { return 0; }
  const std::vector<NestedInteger> &getList() const {
    static auto vec = std::vector<NestedInteger>();
    return vec;
  }
};

class NestedIterator {
 public:
  NestedIterator(std::vector<NestedInteger> &nestedList) {
    for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
      stack_.push(*it);
    }
  }

  int next() {
    auto val = stack_.top();
    stack_.pop();
    return val.getInteger();
  }

  bool hasNext() {
    while (!stack_.empty()) {
      auto val = stack_.top();
      if (val.isInteger()) {
        return true;
      }
      stack_.pop();
      for (auto it = val.getList().rbegin(); it != val.getList().rend(); ++it) {
        stack_.push(*it);
      }
    }
    return false;
  }
 private:
  std::stack<NestedInteger> stack_;
};

int main(int argc, char *argv[]) {
  NestedInteger nestedInteger;
  auto nestedList = nestedInteger.getList();
  NestedIterator i(nestedList);
  while (i.hasNext()) {
    std::cout << i.next() << std::endl;
  }
  return 0;
}
