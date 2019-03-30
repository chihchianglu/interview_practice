//
// Created by Lu, Chih-chiang on 2019-02-21.
//

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
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

// using 2 stacks & a order_flag to do level order traversal + direction change
class Solution {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<std::vector<int>> res;
    std::stack<TreeNode *> stk1{{root}}, stk2;
    std::vector<int> out;
    bool order_flag = true;
    while (!stk1.empty()) {
      TreeNode *cur = stk1.top();
      stk1.pop();
      out.push_back(cur->val);
      if (order_flag) {
        if (cur->left) {
          stk2.push(cur->left);
        }
        if (cur->right) {
          stk2.push(cur->right);
        }
      } else {
        if (cur->right) {
          stk2.push(cur->right);
        }
        if (cur->left) {
          stk2.push(cur->left);
        }
      }

      if (stk1.empty()) {
        if (!out.empty()) {
          res.push_back(out);
          out.clear();
        }
        order_flag = !order_flag;
        stk1 = std::move(stk2);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
