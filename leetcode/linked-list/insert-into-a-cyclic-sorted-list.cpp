//
// Created by Lu, Chih-chiang on 2019-02-15.
//

/**
 * Insert into a Cyclic Sorted List
 *
 * Given a node from a cyclic linked list which is sorted in ascending order, write a function to insert a value into
 * the list such that it remains a cyclic sorted list. The given node can be a reference to any single node in the list,
 * and may not be necessarily the smallest value in the cyclic list.
 *
 * If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the
 * insertion, the cyclic list should remain sorted.
 *
 * If the list is empty (i.e., given node is null), you should create a new single cyclic list and return the reference
 * to that single node. Otherwise, you should return the original given node.
 */

#include <stdexcept>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

class Solution {
 public:
  ListNode *insert(ListNode *head, int insertVal) {
    if (!head) {
      head = new ListNode(insertVal, nullptr);
      head->next = head;
      return head;
    }
    ListNode *prev = head, *cur = prev->next;
    while (cur != head) {
      if (prev->val <= insertVal && cur->val >= insertVal) {
        break;
      } else if (prev->val > cur->val && (prev->val <= insertVal || cur->val >= insertVal)) {
        break;
      }
      prev = cur;
      cur = cur->next;
    }
    prev->next = new ListNode(insertVal, cur);
    return head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
