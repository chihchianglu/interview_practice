//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, find the length of the longest consecutive sequence path.
 *
 * The path refers to any sequence of nodes from some starting node to any node in
 * the tree along the parent-child connections. The longest consecutive path need
 * to be from parent to child (cannot be the reverse).
 *
 * For example,
 *
 *    1
 *     \
 *      3
 *     / \
 *    2   4
 *         \
 *          5
 *
 * Longest consecutive sequence path is 3-4-5, so return 3.
 *
 *    2
 *     \
 *      3
 *     /
 *    2
 *   /
 *  1
 *
 * Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
 */

#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 求increasing sequence only
// 这道题让我们求二叉树的最长连续序列，关于二叉树的题基本都需要遍历树，而递归遍历写起来特别简单，下面这种解法是用到了递归版的先序遍历，
// 我们对于每个遍历到的节点，我们看节点值是否比参数值(父节点值)大1，如果是则长度加1，否则长度重置为1，然后更新结果res，再递归调用左右子节点即可
class Solution {
 public:
  int longestConsecutive(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int res = 0;
    dfs(root, 1, res);
    return res;
  }
  void dfs(TreeNode *root, int len, int &res) {
    res = std::max(res, len);
    if (root->left) {
      if (root->left->val == root->val + 1) {
        dfs(root->left, len + 1, res);
      } else {
        dfs(root->left, 1, res);
      }
    }
    if (root->right) {
      if (root->right->val == root->val + 1) {
        dfs(root->right, len + 1, res);
      } else {
        dfs(root->right, 1, res);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
