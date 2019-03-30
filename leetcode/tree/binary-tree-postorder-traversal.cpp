//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
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

// left -> right -> parent
// use 2 stacks
//  - pop top of the 1st stack & insert into the 2nd stack
//  - push left to the 1st stack
//  - push right to the 1st stack
// reverse the 2nd stack
class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res;
    std::stack<TreeNode *> stk1{{root}}, stk2;
    while (!stk1.empty()) {
      auto *t = stk1.top();
      stk1.pop();
      stk2.push(t);
      if (t->left) {
        stk1.push(t->left);
      }
      if (t->right) {
        stk1.push(t->right);
      }
    }
    // reverse
    while (!stk2.empty()) {
      res.push_back(stk2.top()->val);
      stk2.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
