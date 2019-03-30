//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 */

#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// return -1 means not balanced
class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    return checkDepth(root) >= 0;
  }
  int checkDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int left_height = checkDepth(root->left);
    if (left_height < 0) {
      return -1;
    }
    int right_height = checkDepth(root->right);
    if (right_height < 0) {
      return -1;
    }
    if (std::abs(left_height - right_height) > 1) {
      return -1;
    }
    return 1 + std::max(left_height, right_height);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
