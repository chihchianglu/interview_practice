//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 * Nothing fancy, just perform a preorder traversal for both trees at the same pace, simply return false whenever
 * we found a mismatch, otherwise continue the traversal on both left and right subtrees.
 *
 * Time complexity: O(n)
 * Space complexity: O(1) (ignore recursion stack, otherwise the height of the tree)
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    } else if ((p && !q) || (!p && q) || (p->val != q->val)) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
