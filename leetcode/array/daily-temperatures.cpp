//
// Created by Lu, Chih-chiang on 2018-12-28.
//

/**
 * Daily Temperatures
 *
 * Given a list of daily temperatures, produce a list that, for each day in the input,
 * tells you how many days you would have to wait until a warmer temperature.
 * If there is no future day for which this is possible, put 0 instead.
 *
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 * Note: The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 * The key of solving this problem is to maintain a Decreasing Stack of the indexes
 * of the temperatures, so that whenever we meet a higer temperature, that must be
 * the first time we see it.
 */

#include <stack>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> dailyTemperatures_brute_force(std::vector<int> &T) {
    int n = T.size();
    std::vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = i + 1; j < n; j++) {
        if (T[j] > T[i]) {
          res[i] = j - i;
          break;
        }
      }
    }
    return res;
  }

  static std::vector<int> dailyTemperatures(std::vector<int> &T) {
    int n = T.size();
    std::vector<int> res(n, 0);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && T[i] > T[st.top()]) {
        auto top = st.top();
        st.pop();
        res[top] = i - top;
      }
      st.push(i);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> out = {1, 1, 4, 2, 1, 1, 0, 0};
  if (Solution::dailyTemperatures_brute_force(temp) != out) {
    throw std::runtime_error("error 1");
  }
  if (Solution::dailyTemperatures(temp) != out) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
