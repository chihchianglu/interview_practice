//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Kth Smallest Element in a Sorted Matrix
 *
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order,
 * find the kth smallest element in the matrix.
 *
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Example:
 *
 * matrix = [
 *    [ 1,  5,  9],
 *    [10, 11, 13],
 *    [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    std::priority_queue<int> max_heap;
    for (auto rows : matrix) {
      for (auto val : rows) {
        max_heap.push(val);
        if (max_heap.size() > k) {
          max_heap.pop();
        }
      }
    }
    return max_heap.top();
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  if (Solution::kthSmallest(vec, 8) != 13) {
    throw std::runtime_error("error");
  }
  return 0;
}
