//
// Created by Lu, Chih-chiang on 2019-02-15.
//

/**
 * Intersection of Two Linked Lists
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
  ListNode *getIntersectionNode_v1(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
      return nullptr;
    }
    int size_a = 0, size_b = 0;
    ListNode *a = headA, *b = headB;
    while (a) {
      a = a->next;
      ++size_a;
    }
    while (b) {
      b = b->next;
      ++size_b;
    }
    a = headA;
    b = headB;
    while (size_a > size_b) {
      a = a->next;
      --size_a;
    }
    while (size_a < size_b) {
      b = b->next;
      --size_b;
    }
    while (a != b) {
      a = a->next;
      b = b->next;
    }
    return a;
  }

  // focus on this route
  // go through both lists:
  // 1. with intersection: meet there
  // 2. no intersection: meet in the end after both ptr go through both lists
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
      return nullptr;
    }
    ListNode *a = headA, *b = headB;
    while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }
    return a;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
