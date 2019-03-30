//
// Created by Lu, Chih-chiang on 2019-02-19.
//

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  TreeNode *deleteNode(TreeNode *root, int key) {
    // Base Case: If the tree is empty
    if (!root) {
      return nullptr;
    }

    // Otherwise, recur down the tree
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      // node with only one child or no child
      if (!root->left) {
        return root->right;
      } else if (!root->right) {
        return root->left;
      } else {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        root->val = minValue(root->right);
        // Delete the inorder successor
//        root->right = deleteRec(root->right, root->val);
      }
    }

    return root;
  }
  int minValue(TreeNode *root) {
    while (root->left) {
      root = root->left;
    }
    return root->val;
  };
};

int main(int argc, char *argv[]) {
  return 0;
}
