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
  TreeNode *search(TreeNode *root, int key) {
    if (!root || root->val == key) {
      return root;
    }
    if (key < root->val) {
      return search(root->left, key);
    }
    return search(root->right, key);
  }
  TreeNode *search_v2(TreeNode *root, int key) {
    while (root) {
      if (root->val == key) {
        return root;
      }
      if (key < root->val) {
        root = root->left;
      } else {
        root = root->right;
      }
    }
    return nullptr;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
