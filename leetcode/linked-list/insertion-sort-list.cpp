//
// Created by Lu, Chih-chiang on 2019-02-15.
//

/**
 * Insertion Sort List
 *
 * Sort a linked list using insertion sort.
 *
 * Algorithm of Insertion Sort:
 *
 * Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the
 * sorted list, and inserts it there.
 *
 * It repeats until no input elements remain.
 *
 * Example 1:
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 * Example 2:
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
  ListNode *insertionSortList(ListNode *head) {
    ListNode *res = new ListNode(0), *curr = head;
    while (curr) {
      auto *next = curr->next;
      auto *tmp = res;
      while (tmp->next && tmp->next->val < curr->val) {
        tmp = tmp->next;
      }

      // insert curr between tmp & tmp->next
      curr->next = tmp->next;
      tmp->next = curr;
      curr = next;
    }
    return res->next;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
