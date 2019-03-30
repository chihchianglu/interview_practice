//
// Created by Lu, Chih-chiang on 2019-02-15.
//

/**
 * Copy List with Random Pointer
 *
 * A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include <map>
#include <stdexcept>

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
      return nullptr;
    }

    RandomListNode *res = new RandomListNode(head->label), *copy_node = res, *cur = head->next;
    std::map<RandomListNode *, RandomListNode *> m;
    m[head] = res;
    // go through/copy list
    while (cur) {
      auto *tmp = new RandomListNode(cur->label);
      copy_node->next = tmp;
      m[cur] = tmp;
      cur = cur->next;
      copy_node = copy_node->next;
    }
    cur = head;
    copy_node = res;

    // go through/copy random
    while (copy_node) {
      copy_node->random = m[cur->random];
      cur = cur->next;
      copy_node = copy_node->next;
    }
    return res;
  }

  RandomListNode *copyRandomList_v2(RandomListNode *head) {
    if (!head) {
      return nullptr;
    }
    RandomListNode *cur = head;
    // 生成新节点并接在旧节点后面
    while (cur) {
      auto *new_node = new RandomListNode(cur->label);
      new_node->next = cur->next;
      cur->next = new_node;
      cur = new_node->next;
    }
    cur = head;
    // 给新节点的random字段赋值
    while (cur) {
      if (cur->random) {
        cur->next->random = cur->random->next;
      }
      cur = cur->next->next;
    }
    cur = head;
    // 将新旧节点分开
    RandomListNode *res = head->next;
    while (cur) {
      RandomListNode *new_node = cur->next;
      cur->next = new_node->next;
      if (new_node->next) {
        new_node->next = new_node->next->next;
      }
      cur = cur->next;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
