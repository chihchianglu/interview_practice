//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Best Time to Buy and Sell Stock IV
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * Example 1:
 *
 * Input: [2,4,1], k = 2
 * Output: 2
 *
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 *
 * Example 2:
 *
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 *
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 *              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int solveMaxProfit(std::vector<int> &prices) {
    int res = 0, n = prices.size();
    for (int i = 1; i < n; ++i) {
      res += std::max(0, prices[i] - prices[i - 1]);
    }
    return res;
  }
  // solution = ii + iii
  static int maxProfit(int k, std::vector<int> &prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    } else if (k >= n) {
      return solveMaxProfit(prices);
    }
    // local[i][j]: max profit till day i, j transactions, where there is transaction happening on day i
    std::vector<std::vector<int>> local(n, std::vector<int>(k + 1, 0));
    // global[i][j]: max profit across i days, j transactions
    std::vector<std::vector<int>> global(n, std::vector<int>(k + 1, 0));

    for (int i = 1; i < n; ++i) {
      int diff = prices[i] - prices[i - 1];
      for (int j = 1; j <= k; ++j) {
        // 局部（在第i天交易后，总共交易了j次） =  max{情况2，情况1}
        // 情况1：在第i-1天时，恰好已经交易了j次（local[i-1][j]），那么如果i-1天到i天再交易一次：
        //       即在第i-1天买入，第i天卖出（diff），则这不并不会增加交易次数！
        //      【例如我在第一天买入，第二天卖出；然后第二天又买入，第三天再卖出的行为 和 第一天买入，第三天卖出 的效果是一样的，
        //       其实只进行了一次交易！因为有连续性】
        // 情况2：第i-1天后，共交易了j-1次（global[i-1][j-1]），因此为了满足“第i天过后共进行了j次交易，且第i天必须进行交易”的条件：
        //       我们可以选择1：在第i-1天买入，然后再第i天卖出（diff），或者选择在第i天买入，然后同样在第i天卖出（收益为0）。
        local[i][j] = std::max(global[i - 1][j - 1] + std::max(diff, 0), local[i - 1][j] + diff);
        // 其实上述的递推公式关于local[i][j]的可以稍稍化简一下，
        // 我们之前定义的local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，
        // 然后网友@fgvlty解释了一下第 i 天卖第 j 支股票的话，一定是下面的一种：
        // 1. 今天刚买的
        // 那么 Local(i, j) = Global(i-1, j-1)
        // 相当于啥都没干
        // 2. 昨天买的
        // 那么 Local(i, j) = Global(i-1, j-1) + diff
        // 等于Global(i-1, j-1) 中的交易，加上今天干的那一票
        // 3. 更早之前买的
        // 那么 Local(i, j) = Local(i-1, j) + diff
        // 昨天别卖了，留到今天卖

        // 但其实第一种情况是不需要考虑的，因为当天买当天卖不会增加利润，完全是重复操作，这种情况可以归纳在global[i-1][j-1]中，
        // 所以我们就不需要max(0, diff)了，那么由于两项都加上了diff，所以我们可以把diff抽到max的外面，所以更新后的递推公式为：
        // local[i][j] = std::max(global[i - 1][j - 1], local[i - 1][j]) + diff

        // 全局（到达第i天进行j次交易的最大收益） = max{局部（在第i天交易后，恰好满足j次交易），全局（到达第i-1天时已经满足j次交易）}
        global[i][j] = std::max(local[i][j], global[i - 1][j]);
      }
    }
    return global[n - 1][k];
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 4, 1};
  std::vector<int> vec2 = {3, 2, 6, 5, 0, 3};
  if (Solution::maxProfit(2, vec1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxProfit(2, vec2) != 7) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
