//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Reorder List
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 *
 * Example 1:
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * Example 2:
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
  void reorderList(ListNode *head) {
    if (!head || !head->next) {
      return;
    }

    ListNode *prev = nullptr, *slow = head, *fast = head;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr; // the cut
    ListNode *head_2 = reverseList(slow);

    while (head && head_2) {
      ListNode *tmp1 = head->next;
      ListNode *tmp2 = head_2->next;
      head->next = head_2;
      if (!tmp1) {
        head_2->next = tmp2;
      } else {
        head_2->next = tmp1;
      }
      head = tmp1;
      head_2 = tmp2;
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
