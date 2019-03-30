//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Count of Smaller Numbers After Self
 *
 * You are given an integer array nums and you have to return a new counts array.
 * The counts array has the property where counts[i] is the number of smaller
 * elements to the right of nums[i].
 *
 * Example:
 *
 * Input: [5,2,6,1]
 * Output: [2,1,1,0]
 *
 * Explanation:
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // focus on this solution
  // binary search
  // 将给定数组从最后一个开始，用二分法插入到一个新的数组，这样新数组就是有序的，那么此时该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数
  static std::vector<int> countSmaller_v1(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> tmp, res(n);

    for (int i = n - 1; i >= 0; --i) {
      int left = 0, right = tmp.size();
      while (left < right) {
        int mid = (left + right) / 2;
        if (tmp[mid] >= nums[i]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      res[i] = right;
      tmp.insert(tmp.begin() + right, nums[i]);
    }
    return res;
  }

  // BST
  struct Node {
    int val;
    int smaller;
    Node *left;
    Node *right;
    Node(int v, int s) : val(v), smaller(s), left(nullptr), right(nullptr) {}
  };
  static int insert(Node *&root, int v) {
    if (!root) {
      root = new Node(v, 0);
      return 0;
    }

    if (root->val > v) {
      root->smaller++;
      return insert(root->left, v);
    } else {
      return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
    }
  }
  static std::vector<int> countSmaller(std::vector<int> &nums) {
    std::vector<int> res(nums.size());
    Node *root = nullptr;
    for (int i = nums.size() - 1; i >= 0; --i) {
      res[i] = insert(root, nums[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {5, 2, 6, 1};
  std::vector<int> out = {2, 1, 1, 0};
  if (Solution::countSmaller_v1(vec) != out) {
    throw std::runtime_error("error 1");
  }
  if (Solution::countSmaller(vec) != out) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
