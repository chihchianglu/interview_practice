//
// Created by Lu, Chih-chiang on 2019-03-27.
//

/**
 * Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 *
 * You may assume each number in the sequence is unique.
 *
 * Follow up:
 * Could you do it using only constant space complexity?
 */

// I haven't spent time figuring this out!

#include <stack>
#include <limits>
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
  // 这道题让给了我们一个一维数组，让我们验证其是否为一个二叉搜索树的先序遍历出的顺序，我们都知道二叉搜索树的性质是左<根<右，
  // 如果用中序遍历得到的结果就是有序数组，而先序遍历的结果就不是有序数组了，但是难道一点规律都没有了吗，其实规律还是有的，
  // 根据二叉搜索树的性质，当前节点的值一定大于其左子树中任何一个节点值，而且其右子树中的任何一个节点值都不能小于当前节点值，
  // 那么我们可以用这个性质来验证，举个例子，比如下面这棵二叉搜索树:
  //     5
  //    / \
  //   2   6
  //  / \
  // 1   3
  // 其先序遍历的结果是{5, 2, 1, 3, 6}, 我们先设一个最小值low，然后遍历数组，如果当前值小于这个最小值low，返回false，
  // 对于根节点，我们将其压入栈中，然后往后遍历，如果遇到的数字比栈顶元素小，说明是其左子树的点，继续压入栈中，直到遇到的数字比栈顶元素大，
  // 那么就是右边的值了，我们需要找到是哪个节点的右子树，所以我们更新low值并删掉栈顶元素，然后继续和下一个栈顶元素比较，
  // 如果还是大于，则继续更新low值和删掉栈顶，直到栈为空或者当前栈顶元素大于当前值停止，压入当前值，
  // 这样如果遍历完整个数组之前都没有返回false的话，最后返回true即可
  bool verifyPreorder(std::vector<int> &preorder) {
    int low = std::numeric_limits<int>::min();
    std::stack<int> s;
    for (auto val : preorder) {
      if (val < low) {
        return false;
      }
      while (!s.empty() && val > s.top()) {
        low = s.top();
        s.pop();
      }
      s.push(val);
    }
    return true;
  }
  // 下面这种方法使用了分治法，跟之前那道验证二叉搜索树的题Validate Binary Search Tree的思路很类似，
  // 我们在递归函数中维护一个下界lower和上届upper，那么当前遍历到的节点值必须在(lower, upper)区间之内，
  // 然后我们在给定的区间内搜第一个大于当前节点值的点，然后以此为分界，左右两部分分别调用递归函数，
  // 注意左半部分的upper更新为当前节点值val，表明左子树的节点值都必须小于当前节点值，而右半部分的递归的lower更新为当前节点值val，
  // 表明右子树的节点值都必须大于当前节点值，如果左右两部分的返回结果均为真，则整体返回真
  bool helper(std::vector<int> &preorder, int start, int end, int lower, int upper) {
    if (start > end) return true;
    int val = preorder[start], i = 0;
    if (val <= lower || val >= upper) return false;
    for (i = start + 1; i <= end; ++i) {
      if (preorder[i] >= val) break;
    }
    return helper(preorder, start + 1, i - 1, lower, val) && helper(preorder, i, end, val, upper);
  }
  bool verifyPreorder_v2(std::vector<int> &preorder) {
    return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
