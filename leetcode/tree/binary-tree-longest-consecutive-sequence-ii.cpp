//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
 *
 * Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1]
 * are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be
 * in the child-Parent-child order, where not necessarily be parent-child order.
 *
 * Example 1:
 * Input:
 *
 *         1
 *        / \
 *       2   3
 *
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 *
 * Example 2:
 * Input:
 *
 *         2
 *        / \
 *       1   3
 *
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 *
 * Note: All the values of tree nodes are in the range of [-1e7, 1e7].
 */

#include <utility>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这道题是之前那道Binary Tree Longest Consecutive Sequence的拓展，那道题只让从父结点到子结点这种顺序来找最长连续序列，
// 而这道题没有这个顺序限制，我们可以任意的拐弯，这样能找到最长的递增或者递减的路径。这道题利用回溯的思想比较容易，
// 因为当一个结点没有子结点点时，它只需要跟其父结点进行比较，这种情况最容易处理，而且一旦叶结点处理完了，我们可以一层一层的回溯，
// 直到回到根结点，然后再遍历的过程中不断的更新结果res即可。由于题目中说了要么是递增，要么是递减，我们不能一会递增一会递减，
// 所以我们递增递减的情况都要统计，只是最后取最长的路径。所以我们要知道每一个结点的最长递增和递减路径的长度，当然是从叶结点算起，
// 这样才方便往根结点回溯。当某个结点比其父结点值大1的话，说明这条路径是递增的，那么当我们知道其左右子结点各自的递增路径长度，
// 那么当前结点的递增路径长度就是左右子结点递增路径长度中的较大值加上1，同理如果是递减路径，
// 那么当前结点的递减路径长度就是左右子结点递减路径长度中的较大值加上1，通过这种方式我们可以更新每个结点的递增递减路径长度。
// 在回溯的过程中，一旦我们知道了某个结点的左右子结点的最长递增递减路径长度，那么我们可以算出当前结点的最长连续序列的长度，
// 要么是左子结点的递增路径跟右子结点的递减路径之和加1，要么事左子结点的递减路径跟右子结点的递增路径之和加1，二者中取较大值即可
class Solution {
 public:
  int longestConsecutive(TreeNode *root) {
    int res = 0;
    dfs(root, root, res);
    return res;
  }
  std::pair<int, int> dfs(TreeNode *node, TreeNode *parent, int &res) {
    if (!node) {
      return {0, 0};
    }
    // first travel to the end
    auto left = dfs(node->left, node, res);
    auto right = dfs(node->right, node, res);

    // update res with inc/dec so far
    res = std::max(res, left.first + right.second + 1);
    res = std::max(res, left.second + right.first + 1);

    // update the inc/dec to my parents
    int inc = 0, dec = 0;
    if (node->val == parent->val + 1) {
      inc = std::max(left.first, right.first) + 1;
    } else if (node->val == parent->val - 1) {
      dec = std::max(left.second, right.second) + 1;
    }
    return {inc, dec};
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
