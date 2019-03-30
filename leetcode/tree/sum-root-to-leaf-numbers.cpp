//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
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
  int sumNumbers(TreeNode *root) {
    return sumNumbersDFS(root, 0);
  }
  int sumNumbersDFS(TreeNode *root, int sum) {
    if (!root) {
      return 0;
    }
    sum = 10 * sum + root->val;
    if (!root->left && !root->right) {
      return sum;
    }
    return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
