//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Partition List
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes
 * greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * Example:
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 2 lists, 1 for < x, 1 for >= x
// merge in the end
class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if (!head) {
      return head;
    }
    ListNode *res1 = new ListNode(-1), *res2 = new ListNode(-1);
    ListNode *l1 = res1, *l2 = res2, *cur = head;
    while (cur) {
      if (cur->val < x) {
        l1->next = cur;
        l1 = l1->next;
      } else {
        l2->next = cur;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    l2->next = nullptr;
    l1->next = res2->next;
    return res1->next;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
