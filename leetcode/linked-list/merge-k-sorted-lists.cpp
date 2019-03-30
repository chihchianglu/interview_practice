//
// Created by Lu, Chih-chiang on 2019-02-18.
//

/**
 * Merge k Sorted Lists
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 * Divide and Conquer
 *
 * Time complexity: O(nk Log k)
 */

#include <queue>
#include <vector>
#include <stdexcept>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  struct cmp {
    bool operator()(ListNode *a, ListNode *b) {
      return a->val > b->val;
    }
  };

  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> q;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i]) {
        q.push(lists[i]);
      }
    }

    ListNode *res = new ListNode(-1), *cur = res;
    while (!q.empty()) {
      cur->next = q.top();
      q.pop();
      cur = cur->next;
      if (cur->next) {
        q.push(cur->next);
      }
    }
    return res->next;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
