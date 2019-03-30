//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *res = new ListNode(-1), *prev = res;
    res->next = head;
    while (prev->next && prev->next->next) {
      ListNode *tmp = prev->next->next;
      prev->next->next = tmp->next;
      tmp->next = prev->next;
      prev->next = tmp;
      prev = tmp->next;
    }
    return res->next;
  }
  ListNode *swapPairs_v2(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *tmp = head->next;
    head->next = swapPairs_v2(head->next->next);
    tmp->next = head;
    return tmp;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
