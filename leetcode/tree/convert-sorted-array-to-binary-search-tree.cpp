//
// Created by Lu, Chih-chiang on 2019-02-24.
//

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// binary search-ish way to build the BST
class Solution {
 public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return helper(nums, 0, (int) nums.size() - 1);
  }
  TreeNode *helper(std::vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *cur = new TreeNode(nums[mid]);
    cur->left = helper(nums, left, mid - 1);
    cur->right = helper(nums, mid + 1, right);
    return cur;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
