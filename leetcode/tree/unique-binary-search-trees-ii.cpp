//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这道题是之前的 Unique Binary Search Trees 独一无二的二叉搜索树的延伸，之前那个只要求算出所有不同的二叉搜索树的个数，
// 这道题让把那些二叉树都建立出来。这种建树问题一般来说都是用递归来解，这道题也不例外，划分左右子树，递归构造。
class Solution {
 public:
  std::vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    return genBST(1, n);
  }

  std::vector<TreeNode *> genBST(int min, int max) {
    std::vector<TreeNode *> res;
    if (min > max) {
      res.push_back(nullptr);
      return res;
    }
    for (int i = min; i <= max; ++i) {
      std::vector<TreeNode *> left_sub_tree = genBST(min, i - 1);
      std::vector<TreeNode *> right_sub_tree = genBST(i + 1, max);
      for (int j = 0; j < left_sub_tree.size(); ++j) {
        for (int k = 0; k < right_sub_tree.size(); ++k) {
          TreeNode *root = new TreeNode(i);
          root->left = left_sub_tree[j];
          root->right = right_sub_tree[k];
          res.push_back(root);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
