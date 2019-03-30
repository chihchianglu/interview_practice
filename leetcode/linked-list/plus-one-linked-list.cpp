//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Plus One Linked List
 *
 * Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example:
 *
 * Input:
 * 1->2->3
 *
 * Output:
 * 1->2->4
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *plusOne(ListNode *head) {
    if (!helper(head)) {
      return head;
    }
    ListNode *new_head = new ListNode(1);
    new_head->next = head;
    return new_head;
  }

  // return the carry
  int helper(ListNode *node) {
    if (!node) {
      return 1;
    }

    int carry = helper(node->next);
    int sum = node->val + carry;
    node->val = sum % 10;
    return sum / 10;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
