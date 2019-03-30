//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 */

#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// build the string while traveling down to leaf
// when u reach leaf, just add the string to res
class Solution {
 public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> res;
    if (root) {
      dfs(root, "", res);
    }
    return res;
  }
  void dfs(TreeNode *node, std::string out, std::vector<std::string> &res) {
    if (!node->left && !node->right) {
      res.push_back(out + std::to_string(node->val));
      return;
    }
    if (node->left) {
      dfs(node->left, out + std::to_string(node->val) + "->", res);
    }
    if (node->right) {
      dfs(node->right, out + std::to_string(node->val) + "->", res);
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
