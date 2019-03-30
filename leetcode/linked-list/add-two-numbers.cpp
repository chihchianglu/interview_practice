//
// Created by Lu, Chih-chiang on 2019-02-10.
//

/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include <stdexcept>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode(-1);
    auto *cur = res;
    int carry = 0;
    while (l1 || l2) {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry) {
      cur->next = new ListNode(1);
    }
    return res->next;
  }
};

int main(int argc, char *argv[]) {
  ListNode *list_1_1 = new ListNode(2);
  list_1_1->next = new ListNode(4);
  list_1_1->next->next = new ListNode(3);
  ListNode *list_2_1 = new ListNode(5);
  list_2_1->next = new ListNode(6);
  list_2_1->next->next = new ListNode(4);

  ListNode *out_1 = new ListNode(7);
  out_1->next = new ListNode(0);
  out_1->next->next = new ListNode(8);

  auto *res = Solution::addTwoNumbers(list_1_1, list_2_1);

  while (out_1 || res) {
    if (out_1->val != res->val) {
      throw std::runtime_error("error");
    }
    out_1 = out_1->next;
    res = res->next;
  }

  return 0;
}
