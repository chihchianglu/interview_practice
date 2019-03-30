//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Palindrome Linked List
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 * Input: 1->2
 * Output: false
 * Example 2:
 *
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

#include <stack>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
      return true;
    }

    ListNode *slow = head, *fast = head;
    std::stack<int> stk;
    stk.push(head->val);
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      stk.push(slow->val);
    }
    if (!fast->next) {
      stk.pop();
    }
    while (slow->next) {
      slow = slow->next;
      int tmp = stk.top();
      stk.pop();
      if (tmp != slow->val) {
        return false;
      }
    }
    return true;
  }
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  bool isPalindrome_v2(ListNode *head) {
    if (!head || !head->next) {
      return true;
    }
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *l2 = !fast->next ? reverse(slow->next) : reverse(slow), *l1 = head;
    while (l1 && l2) {
      if (l1->val != l2->val) {
        return false;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
