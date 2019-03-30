//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Best Time to Buy and Sell Stock with Cooldown
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 *
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 * The possible states are as follows:
 *
 *                    rest <--> rest
 *                   /  /\
 *              buy /     \
 *                \/       \
 *     rest <--> hold ----> sold
 *                    sell
 *
 * sold[i] = hold[i - 1] + prices[i]
 * hold[i] = max(hold[i - 1], rest[i - 1] - prices[i])
 * rest[i] = max(rest[i - 1], sold[i - 1])
 *
 * init: rest[0] = sold[0] = 0, hold[0] = -∞
 * ans: max(rest[i], sold[i])
 *
 * Time complexity: O(n)
 * Space complexity O(n) -> O(1)
 */

#include <vector>
#include <limits>
#include <stdexcept>

// buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
// sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
// rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。
// buy[i]  = max(rest[i-1] - price, buy[i-1])
// sell[i] = max(buy[i-1] + price, sell[i-1])
// rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
// 由於冷凍其存在，我们可以得出rest[i] = sell[i-1]，这样，我们可以将上面三个递推式精简到两个
// buy[i]  = max(sell[i-2] - price, buy[i-1])
// sell[i] = max(buy[i-1] + price, sell[i-1])
class Solution {
 public:
  static int maxProfit(std::vector<int> &prices) {
    int sold = 0, rest = 0, hold = std::numeric_limits<int>::min();
    for (int price : prices) {
      int prev_sold = sold;
      sold = hold + price;
      hold = std::max(hold, rest - price);
      rest = std::max(rest, prev_sold);
    }
    return std::max(rest, sold);
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 0, 2};
  if (Solution::maxProfit(vec) != 3) {
    throw std::runtime_error("error");
  }
  return 0;
}
