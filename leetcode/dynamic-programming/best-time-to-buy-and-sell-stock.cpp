//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Best Time to Buy and Sell Stock
 *
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 * Example 2:
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#include <cmath>
#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int maxProfit(std::vector<int> &prices) {
    int res = 0, buy = std::numeric_limits<int>::max();
    for (int price : prices) {
      buy = std::min(buy, price);
      res = std::max(res, price - buy);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {7, 1, 5, 3, 6, 4};
  std::vector<int> vec2 = {7, 6, 4, 3, 1};
  if (Solution::maxProfit(vec1) != 5) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxProfit(vec2) != 0) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
