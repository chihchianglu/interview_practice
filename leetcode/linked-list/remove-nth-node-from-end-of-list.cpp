//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Remove Nth Node From End of List
 *
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Example:
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 *
 * Given n will always be valid.
 *
 * Follow up:
 *
 * Could you do this in one pass?
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head->next) {
      return nullptr;
    }
    ListNode *prev = head, *cur = head;
    for (int i = 0; i < n; ++i) {
      cur = cur->next;
    }
    if (!cur) {
      return head->next;
    }
    while (cur->next) {
      cur = cur->next;
      prev = prev->next;
    }
    prev->next = prev->next->next;
    return head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
