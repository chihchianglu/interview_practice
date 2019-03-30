//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
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

// parent -> left -> right
// use 1 stack
//  - pop top & insert into to the back
//  - push right
//  - push left
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res;
    std::stack<TreeNode *> stk1{{root}};
    while (!stk1.empty()) {
      auto *t = stk1.top();
      stk1.pop();
      res.push_back(t->val);
      if (t->right) {
        stk1.push(t->right);
      }
      if (t->left) {
        stk1.push(t->left);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
