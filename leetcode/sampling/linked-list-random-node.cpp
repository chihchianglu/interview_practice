//
// Created by Lu, Chih-chiang on 2019-01-14.
//

/**
 * Linked List Random Node
 *
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 *
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 *
 * Example:
 *
 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 *
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 * solution.getRandom();
 *
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

#include <cstdlib>
#include <stdexcept>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_v1 {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution_v1(ListNode *head) {
    head_ = head;
    while (head) {
      ++length_;
      head = head->next;
    }
  }

  /** Returns a random node's value. */
  int getRandom() {
    int count = std::rand() % length_;
    ListNode *ret = head_;
    while (count--) {
      ret = ret->next;
    }
    return ret->val;
  }

 private:
  int length_;
  ListNode *head_;
};

// Follow up中说链表可能很长，我们没法提前知道长度，这里用到了著名了水塘抽样Reservoir Sampling的思路，由于限定了head一定存在，
// 所以我们先让返回值res等于head的节点值，然后让cur指向head的下一个节点，定义一个变量i，初始化为2，若cur不为空我们开始循环，
// 我们在[0, i - 1]中取一个随机数，如果取出来0，那么我们更新res为当前的cur的节点值，然后此时i自增一，cur指向其下一个位置，
// 这里其实相当于我们维护了一个大小为1的水塘，然后我们随机数生成为0的话，我们交换水塘中的值和当前遍历到的值，这样可以保证每个数字的概率相等

// 從S中抽取首k項放入「水塘」中
// 對於每一個S[j]項（j ≥ k）：
//    隨機產生一個範圍從0到j的整數r
//    若 r < k 則把水塘中的第r項換成S[j]項
class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode *head) {
    head_ = head;
  }

  /** Returns a random node's value. */
  int getRandom() {
    int res = 0, count = 1;
    ListNode *cur = head_;

    while (cur) {
      if (std::rand() % count == 0) {
        res = cur->val;
      }
      ++count;
      cur = cur->next;
    }
    return res;
  }

 private:
  ListNode *head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(int argc, char *argv[]) {
  auto head = new ListNode(1);
  auto obj1 = new Solution(head);
  int out1 = obj1->getRandom();
  if (out1 != 1) {
    throw std::runtime_error("error 1");
  }
  auto obj2 = new Solution(head);
  head->next = new ListNode(2);
  int out2 = obj2->getRandom();
  if (out2 != 1) {
    throw std::runtime_error("error 2");
  }

  auto obj3 = new Solution(head);
  head->next->next = new ListNode(3);
  int out3 = obj3->getRandom();
  if (out3 != 2) {
    throw std::runtime_error("error 3");
  }

  return 0;
}
