//
// Created by Lu, Chih-chiang on 2019-02-22.
//

/**
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 *
 * Note:
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
 */

#include <cmath>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int closestValue_v1(TreeNode *root, double target) {
    int res = root->val;
    while (root) {
      if (std::abs(res - target) >= std::abs(root->val - target)) {
        res = root->val;
      }
      root = target < root->val ? root->left : root->right;
    }
    return res;
  }

  // focus on this route
  int closestValue(TreeNode *root, double target) {
    TreeNode *child = target < root->val ? root->left : root->right;
    if (!child) {
      return root->val;
    }
    int closest = closestValue(child, target);
    return std::abs(root->val - target) < std::abs(closest - target) ? root->val : closest;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
