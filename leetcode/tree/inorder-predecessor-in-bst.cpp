//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary search tree and a node in it, find the in-order predecessor of that node in the BST.
 *
 * Note: If the given node has no in-order predecessor in the tree, return null.
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p) {
    if (!root) {
      return nullptr;
    }

    if (root->val >= p->val) {
      return inorderPredecessor(root->left, p);
    } else {
      TreeNode *predecessor = inorderPredecessor(root->right, p);
      return predecessor ? predecessor : root;
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
