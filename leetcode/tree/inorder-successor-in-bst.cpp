//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 *
 * Note: If the given node has no in-order successor in the tree, return null.
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
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (!root) {
      return nullptr;
    }
    if (root->val <= p->val) {
      inorderSuccessor(root->right, p);
    } else {
      TreeNode *successor = inorderSuccessor(root->left, p);
      return successor ? successor : root;
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
