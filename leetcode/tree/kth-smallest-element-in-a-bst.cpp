//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Kth Smallest Element in a BST
 *
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Example 1:
 *
 * Input: root = [3,1,4,null,2], k = 1
 *
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 *
 * Output: 1
 *
 * Example 2:
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 *
 * Output: 3
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 * How would you optimize the kthSmallest routine?
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution 1: inorder traversal
// solution 2: divide & conquer
class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    return kthSmallestDFS(root, k);
  }
  int kthSmallestDFS(TreeNode *root, int &k) {
    if (!root) {
      return -1;
    }
    int val = kthSmallestDFS(root->left, k);
    if (k == 0) {
      return val;
    } else if (--k == 0) {
      return root->val;
    }
    return kthSmallestDFS(root->right, k);
  }

  int kthSmallest_v2(TreeNode *root, int k) {
    int cnt = count(root->left);
    if (k <= cnt) {
      return kthSmallest_v2(root->left, k);
    } else if (k > cnt + 1) {
      return kthSmallest_v2(root->right, k - cnt - 1);
    }
    return root->val;
  }
  int count(TreeNode *node) {
    if (!node) {
      return 0;
    }
    return 1 + count(node->left) + count(node->right);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
