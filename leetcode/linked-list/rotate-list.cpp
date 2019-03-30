//
// Created by Lu, Chih-chiang on 2019-02-19.
//

/**
 * Rotate List
 *
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 *
 * Example 1:
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 *
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 * Example 2:
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 *
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 1. loop through the end to point end to head
// 2. keep going to cut the new end
class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
      ++n;
      cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; ++i) {
      cur = cur->next;
    }
    ListNode *new_head = cur->next;
    cur->next = nullptr;
    return new_head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
