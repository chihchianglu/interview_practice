//
// Created by Lu, Chih-chiang on 2019-02-15.
//

/**
 * Linked List Components
 *
 * We are given head, the head node of a linked list containing unique integer values.
 *
 * We are also given the list G, a subset of the values in the linked list.
 *
 * Return the number of connected components in G, where two values are connected if they
 * appear consecutively in the linked list.
 *
 * Example 1:
 *
 * Input:
 * head: 0->1->2->3
 * G = [0, 1, 3]
 * Output: 2
 *
 * Explanation:
 * 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
 *
 * Example 2:
 *
 * Input:
 * head: 0->1->2->3->4
 * G = [0, 3, 1, 4]
 * Output: 2
 *
 * Explanation:
 * 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 *
 * Note:
 *
 * If N is the length of the linked list given by head, 1 <= N <= 10000.
 * The value of each node in the linked list will be in the range [0, N - 1].
 * 1 <= G.length <= 10000.
 * G is a subset of all values in the linked list.
 */

#include <vector>
#include <stdexcept>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 这道题给了我们一个链表，又给了我们一个结点值数组，里面不一定包括了链表中所有的结点值。
// 让我们返回结点值数组中有多少个相连的组件，因为缺失的结点值会将原链表断开，实际上就是让我们求有多少个相连的子链表，
// 题目中给的例子很好的说明题意。这道题并不需要什么特别高深的技巧，难懂的算法，直接按题目的要求来找就可以了。
// 首先，为了快速的在结点值数组中查找某个结点值是否存在，我们可以将所有的结点值放到一个HashSet中，
// 这样我们就能在常数级的时间复杂度中查找。然后我们就可以来遍历链表了，对于遍历到的每个结点值，我们只有两种情况，
// 在或者不在HashSet中。不在HashSet中的情况比较好办，说明此时断开了，而在HashSet中的结点，有可能是该连续子链表的起始点，
// 或者是中间的某个点，而我们的计数器对该子链表只能自增1，所以我们需要想办法来hanlde这种情况。
// 博主最先想到的办法是先处理不在HashSet中的结点，处理方法就是直接跳到下一个结点。那么对于在HashSet中的结点，
// 我们首先将计数器res自增1，然后再来个循环，将之后所有在集合中的结点都遍历完，这样才不会对同一个子链表多次增加计数器
class Solution {
 public:
  int numComponents(ListNode *head, std::vector<int> &G) {
    int res = 0;
    std::unordered_set<int> s(G.begin(), G.end());
    while (head) {
      if (!s.count(head->val)) {
        head = head->next;
        continue;
      }
      head = head->next;
      ++res;
      while (head && s.count(head->val)) {
        head = head->next;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
