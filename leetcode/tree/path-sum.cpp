//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such
 * that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// keep deducting sum down the path
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right && root->val == sum) {
      return true;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
