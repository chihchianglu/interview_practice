//
// Created by Lu, Chih-chiang on 2019-02-20.
//

/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

#include <queue>
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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      std::vector<int> one_level;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *t = q.front();
        q.pop();
        one_level.push_back(t->val);
        if (t->left) {
          q.push(t->left);
        }
        if (t->right) {
          q.push(t->right);
        }
      }
      res.push_back(one_level);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
