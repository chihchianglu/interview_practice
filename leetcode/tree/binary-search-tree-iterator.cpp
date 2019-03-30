//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Binary Search Tree Iterator
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

#include <stack>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    while (root) {
      stk_.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *res = stk_.top();
    stk_.pop();
    if (res->right) {
      auto *node = res->right;
      while (node) {
        stk_.push(node);
        node = node->left;
      }
    }
    return res->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stk_.empty();
  }
 private:
  std::stack<TreeNode *> stk_;
};

int main(int argc, char *argv[]) {
  return 0;
}
