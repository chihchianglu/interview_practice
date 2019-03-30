//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Queue Reconstruction by Height
 *
 * Suppose you have a random list of people standing in a queue.
 * Each person is described by a pair of integers (h, k),
 * where h is the height of the person and k is the number of people in front of this person
 * who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 *
 * Example
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

#include <vector>
#include <algorithm>
#include <stdexcept>

// 这道题给了我们一个队列，队列中的每个元素是一个pair，分别为身高和前面身高不低于当前身高的人的个数，让我们重新排列队列，
// 使得每个pair的第二个参数都满足题意。首先我们来看一种超级简洁的方法，不得不膜拜想出这种解法的大神。首先我们给队列先排个序，
// 按照身高高的排前面，如果身高相同，则第二个数小的排前面。然后我们新建一个空的数组，遍历之前排好序的数组，
// 然后根据每个元素的第二个数字，将其插入到res数组中对应的位置
class Solution {
 public:
  static std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>> &people) {
    std::sort(people.begin(),
              people.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                return a.first > b.first || (a.first == b.first && a.second < b.second);
              });
    std::vector<std::pair<int, int>> res;
    for (auto &p : people) {
      res.insert(res.begin() + p.second, p);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> vec = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  std::vector<std::pair<int, int>> out = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
  if (Solution::reconstructQueue(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
