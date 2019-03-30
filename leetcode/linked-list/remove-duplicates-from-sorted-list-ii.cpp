//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Remove Duplicates from Sorted List II
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Example 1:
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * Example 2:
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *res = new ListNode(-1), *prev = res;
    res->next = head;

    while (prev->next) {
      ListNode *cur = prev->next;
      while (cur->next && cur->val == cur->next->val) {
        cur = cur->next;
      }
      if (prev->next != cur) {
        // means we found duplicate & moved
        prev->next = cur->next;
      } else {
        prev = prev->next;
      }
    }
    return res->next;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
