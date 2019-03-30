//
// Created by Lu, Chih-chiang on 2019-02-22.
//

/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这道题要求用先序和中序遍历来建立二叉树，跟之前那道Construct Binary Tree from Inorder and Postorder Traversal
// 由中序和后序遍历建立二叉树原理基本相同，针对这道题，由于先序的顺序的第一个肯定是根，所以原二叉树的根节点可以知道，
// 题目中给了一个很关键的条件就是树中没有相同元素，有了这个条件我们就可以在中序遍历中也定位出根节点的位置，
// 并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用原函数。
class Solution {
 public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  TreeNode *buildTree(std::vector<int> &preorder,
                      int pLeft,
                      int pRight,
                      std::vector<int> &inorder,
                      int iLeft,
                      int iRight) {
    if (pLeft > pRight || iLeft > iRight) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pLeft]); // get the root value
    int pos = 0;
    for (pos = iLeft; pos <= iRight; ++pos) {
      if (preorder[pLeft] == inorder[pos]) {
        break;
      }
    }
    // build the left and right subtrees recursively
    // pLeft + (pos - iLeft) -> left subtree end point
    // pLeft + (pos - iLeft) + 1 -> right subtree start point
    root->left = buildTree(preorder, pLeft + 1, pLeft + pos - iLeft, inorder, iLeft, pos - 1);
    root->right = buildTree(preorder, pLeft + pos - iLeft + 1, pRight, inorder, pos + 1, iRight);
    return root;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
