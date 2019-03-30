//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Remove Linked List Elements
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  // add a extra node, to smooth the iteration
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *res = new ListNode(-1), *prev = res;
    res->next = head;
    while (prev->next) {
      if (prev->next->val == val) {
        ListNode *tmp = prev->next;
        prev->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;
      } else {
        prev = prev->next;
      }
    }
    return res->next;
  }
  ListNode *removeElements_v2(ListNode *head, int val) {
    if (!head) {
      return nullptr;
    }
    head->next = removeElements_v2(head->next, val);
    return head->val == val ? head->next : head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
