//
// Created by Lu, Chih-chiang on 2019-02-10.
//

/**
 * Add Two Numbers II
 *
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes
 * first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */

#include <stack>
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
    std::stack<int> s1, s2;
    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }
    int sum = 0;
    ListNode *res = new ListNode(0);
    while (!s1.empty() || !s2.empty()) {
      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }
      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }
      res->val = sum % 10;
      ListNode *head = new ListNode(sum / 10); // for the case: 5 + 5
      head->next = res;
      res = head;
      sum /= 10;
    }
    return res->val == 0 ? res->next : res;
  }
};

int main(int argc, char *argv[]) {
  ListNode *list_1_1 = new ListNode(7);
  list_1_1->next = new ListNode(2);
  list_1_1->next->next = new ListNode(4);
  list_1_1->next->next->next = new ListNode(3);
  ListNode *list_2_1 = new ListNode(5);
  list_2_1->next = new ListNode(6);
  list_2_1->next->next = new ListNode(4);

  ListNode *out_1 = new ListNode(7);
  out_1->next = new ListNode(8);
  out_1->next->next = new ListNode(0);
  out_1->next->next->next = new ListNode(7);

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
