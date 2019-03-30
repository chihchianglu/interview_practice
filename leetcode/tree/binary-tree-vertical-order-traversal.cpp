//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be from left to right.
 *
 * Examples:
 * Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * return its vertical order traversal as:
 * [
 *   [9],
 *   [3,15],
 *   [20],
 *   [7]
 * ]
 *
 * Given binary tree [3,9,20,4,5,2,7],
 *     _3_
 *    /   \
 *   9    20
 *  / \   / \
 * 4   5 2   7
 * return its vertical order traversal as:
 * [
 *   [4],
 *   [9],
 *   [3,5,2],
 *   [20],
 *   [7]
 * ]
 */

#include <map>
#include <queue>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这道题让我们竖直遍历二叉树，并把每一列存入一个二维数组，我们看题目中给的第一个例子，3和15属于同一列，3在前，
// 第二个例子中，3,5,2在同一列，3在前，5和2紧随其后，那么我们隐约的可以感觉到好像是一种层序遍历的前后顺序，
// 那么我们如何来确定列的顺序呢，我们可以把根节点给个序号0，然后开始层序遍历，凡是左子节点则序号减1，右子节点序号加1，
// 这样我们可以通过序号来把相同列的节点值放到一起，我们用一个TreeMap来建立序号和其对应的节点值的映射，
// 用TreeMap的另一个好处是其自动排序功能可以让我们的列从左到右，由于层序遍历需要用到queue，我们此时queue里不能只存节点，
// 而是要存序号和节点组成的pair，这样我们每次取出就可以操作序号，而且排入队中的节点也赋上其正确的序号
class Solution {
 public:
  std::vector<std::vector<int>> verticalOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    if (!root) {
      return res;
    }
    std::map<int, std::vector<int>> m; // mapping between sequence# <-> nodes
    std::queue<std::pair<int, TreeNode *>> q; // pair of sequence# & node
    q.push(std::make_pair(0, root));
    while (!q.empty()) {
      auto pair = q.front();
      q.pop();
      m[pair.first].push_back(pair.second->val);
      if (pair.second->left) {
        q.push(std::make_pair(pair.first - 1, pair.second->left));
      }
      if (pair.second->right) {
        q.push(std::make_pair(pair.first + 1, pair.second->right));
      }
    }
    // m contains all the nodes in vertical order(based on sequence#)
    for (auto itr : m) {
      // already sorted based on sequence#
      res.push_back(itr.second);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
