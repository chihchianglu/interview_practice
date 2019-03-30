//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * Largest Rectangle in Histogram
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the
 * area of largest rectangle in the histogram.
 *
 * Example:
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 */

#include <stack>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  // O(n * n)
  static int largestRectangleArea_v1(std::vector<int> &heights) {
    int res = 0, n = heights.size();
    for (int i = 0; i < n; ++i) {
      if (i < n - 1 && heights[i] <= heights[i + 1]) {
        continue;
      }
      int min_h = heights[i];
      for (int j = i; j >= 0; --j) {
        min_h = std::min(min_h, heights[j]);
        int area = min_h * (i - j + 1);
        res = std::max(res, area);
      }
    }
    return res;
  }

  static int largestRectangleArea(std::vector<int> &heights) {
    int res = 0;
    std::stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        int cur = st.top();
        st.pop();
        res = std::max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
      }
      st.push(i);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 1, 5, 6, 2, 3};
  if (Solution::largestRectangleArea_v1(vec) != 10) {
    throw std::runtime_error("error 1");
  }
  if (Solution::largestRectangleArea(vec) != 10) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
