//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
