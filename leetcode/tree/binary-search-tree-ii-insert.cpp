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
  TreeNode *insert(TreeNode *root, int key) {
    // If the tree is empty, return a new node
    if (!root) {
      return new TreeNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->val) {
      root->left = insert(root->left, key);
    } else if (key > root->val) {
      root->right = insert(root->right, key);
    }
    // Return the (unchanged) node pointer
    return root;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
