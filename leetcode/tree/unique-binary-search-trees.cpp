//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <vector>

// 定义dp(n)为unique BST的数量，以n = 3为例：
// 构造的BST的根节点可以取{1, 2, 3}中的任一数字。
// 如以1为节点，则left subtree只能有0个节点，而right subtree有2, 3两个节点。
// 所以left/right subtree一共的combination数量为：f(0) * f(2) = 2
// 以2为节点，则left subtree只能为1，right subtree只能为2：f(1) * f(1) = 1
// 以3为节点，则left subtree有1, 2两个节点，right subtree有0个节点：f(2)*f(0) = 2
// 总结规律：
// dp(0) = 1
// dp(n) = dp(0)*dp(n-1) + dp(1)*dp(n-2) + ... + dp(n-2)*dp(1) + dp(n-1)*dp(0)
// 我们根据以上的分析，可以写出代码如下：
class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
