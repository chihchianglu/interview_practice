//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <stack>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    dfs(root, res);
    return res;
  }
  void dfs(TreeNode *root, std::vector<int> &res) {
    if (!root) {
      return;
    }
    if (root->left) {
      dfs(root->left, res);
    }
    res.push_back(root->val);
    if (root->right) {
      dfs(root->right, res);
    }
    return;
  }
  // use stack to implement iteration inorder traversal
  // keep pushing to the stack & travel to the left
  // when hit the end, pop the stack & move to right
  std::vector<int> inorderTraversal_v2(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    TreeNode *cur = root;
    while (!s.empty() || cur) {
      if (cur) {
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
