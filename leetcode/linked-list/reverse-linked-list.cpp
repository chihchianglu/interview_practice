//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Reverse Linked List
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  ListNode *reverseList_v2(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *new_head = reverseList_v2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
