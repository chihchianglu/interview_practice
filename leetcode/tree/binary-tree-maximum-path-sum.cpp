//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The path must contain at least one node and does
 * not need to go through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 *
 * Return 6.
 *
 * The helper function returns the max path including the current node's value.
 */

#include <limits>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    int res = std::numeric_limits<int>::min();
    dfs(root, res);
    return res;
  }
  int dfs(TreeNode *node, int &res) {
    if (!node) {
      return 0;
    }

    // travel to the leaf, then trace back
    int left = std::max(dfs(node->left, res), 0);
    int right = std::max(dfs(node->right, res), 0);
    res = std::max(res, left + right + node->val);
    return std::max(left, right) + node->val;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
