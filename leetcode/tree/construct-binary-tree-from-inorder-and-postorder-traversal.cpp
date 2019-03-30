//
// Created by Lu, Chih-chiang on 2019-02-22.
//

/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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

// 这道题要求从中序和后序遍历的结果来重建原二叉树，我们知道中序的遍历顺序是左-根-右，后序的顺序是左-右-根，对于这种树的重建一般都是采用递归来做，
// 可参见我之前的一篇博客Convert Sorted Array to Binary Search Tree 将有序数组转为二叉搜索树。针对这道题，由于后序的顺序的最后一个肯定是根，
// 所以原二叉树的根节点可以知道，题目中给了一个很关键的条件就是树中没有相同元素，有了这个条件我们就可以在中序遍历中也定位出根节点的位置，
// 并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用原函数

class Solution {
 public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
  TreeNode *buildTree(std::vector<int> &inorder,
                      int iLeft,
                      int iRight,
                      std::vector<int> &postorder,
                      int pLeft,
                      int pRight) {
    if (iLeft > iRight || pLeft > pRight) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[pRight]); // get the root value
    // get inorder root position
    int pos = 0;
    for (pos = iLeft; pos < iRight; ++pos) {
      if (inorder[pos] == root->val) {
        break;
      }
    }
    // build the left and right subtrees recursively
    // pLeft + (pos - iLeft) - 1 -> left subtree end point
    // pLeft + (pos - iLeft) -> right subtree start point
    root->left = buildTree(inorder, iLeft, pos - 1, postorder, pLeft, pLeft + pos - iLeft - 1);
    root->right = buildTree(inorder, pos + 1, iRight, postorder, pLeft + pos - iLeft, pRight - 1);
    return root;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
