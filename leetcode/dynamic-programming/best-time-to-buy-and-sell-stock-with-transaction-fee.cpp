//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Best Time to Buy and Sell Stock with Transaction Fee
 *
 * Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i;
 * and a non-negative integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
 * You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
 *
 * Return the maximum profit you can make.
 *
 * Example 1:
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 *
 * Explanation: The maximum profit can be achieved by:
 *
 * Buying at prices[0] = 1
 * Selling at prices[3] = 8
 * Buying at prices[4] = 4
 * Selling at prices[5] = 9
 *
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 *
 * Note:
 *
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 *
 * At the end of the i-th day, we maintain cash, the maximum profit we could have if we did not have a share of stock,
 * and hold, the maximum profit we could have if we owned a share of stock.
 *
 * To transition from the i-th day to the i+1-th day,
 *
 *
 * we either sell our stock:
 * cash = max(cash, hold + prices[i] - fee)
 *
 * or buy a stock:
 * hold = max(hold, cash - prices[i]).
 *
 * At the end, we want to return cash. We can transform cash first without using temporary variables because
 * selling and buying on the same day can't be better than just continuing to hold the stock.
 */

#include <vector>
#include <stdexcept>

// summary: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
class Solution {
 public:
  static int maxProfit_v1(std::vector<int> &prices, int fee) {
    // sold[i]表示第i天卖掉股票此时的最大利润，hold[i]表示第i天保留手里的股票此时的最大利润
    std::vector<int> sold(prices.size(), 0), hold = sold;
    hold[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      sold[i] = std::max(sold[i - 1], hold[i - 1] + prices[i] - fee); // pay the fee during sell
      hold[i] = std::max(hold[i - 1], sold[i - 1] - prices[i]);
    }
    return sold.back();
  }
  static int maxProfit(std::vector<int> &prices, int fee) {
    int cash = 0;// 用来统计当前的利润现金
    int hold = -prices[0];// 用来计算当前的股票
    for (int i = 1; i < prices.size(); i++) {
      cash = std::max(cash, prices[i] + hold - fee);// 比较当前现金和如果出售手头股票赚到的利润
      hold = std::max(hold, cash - prices[i]);// 比较当前的股票和如果购买股票之后手上剩下的钱
    }
    return cash;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 3, 2, 8, 4, 9};
  if (Solution::maxProfit_v1(vec, 2) != 8) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxProfit(vec, 2) != 8) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
