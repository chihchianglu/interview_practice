//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// need to check line 27 ~ 30 because of situation like:
//    2
//   /
//  1
// should return 2 instead of 1
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    } else if (!root->left) {
      return 1 + minDepth(root->right);
    } else if (!root->right) {
      return 1 + minDepth(root->left);
    }
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
