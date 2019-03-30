//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Task Scheduler
 *
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
 * represent different tasks. Tasks could be done without original order.
 * Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks,
 * there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 *
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 *
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 * Note:
 *
 * - The number of tasks is in the range [1, 10000].
 * - The integer n is in the range [0, 100].
 *
 * Solution:
 *
 * Example 1:
 *
 * AAAABBBEEFFGG 3
 *
 * step 1: A---A---A---A
 * step 2: AB--AB--AB--A
 * step 3: ABE-ABE-AB--A
 * step 4: ABEFABE-ABF-A
 * step 5: ABEFABEGABFGA
 *
 * Example 2:
 *
 * ACCCEEE 2
 *
 * step 1: CE-CE-CE
 * step 2: CEACE-CE
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int leastInterval(std::vector<char> &tasks, int n) {
    // Step 1. count the max occurrence and how many tasks have the same max count
    int mx = 0, mx_count = 0;
    std::vector<int> count(26, 0);
    for (auto task : tasks) {
      ++count[task - 'A'];
      if (mx == count[task - 'A']) {
        ++mx_count;
      } else if (mx < count[task - 'A']) {
        mx = count[task - 'A'];
        mx_count = 1;
      }
    }

    // Step 2. group the max occurance chars together, e.g. CE-CE-CE
    // update the left cooling intervals in each group
    int part_count = mx - 1;
    int part_length = n - (mx_count - 1);

    // Step 3. put the rest tasks into the empty slots
    int empty_slots = part_count * part_length;
    int task_left = tasks.size() - mx * mx_count;
    int idles = std::max(0, empty_slots - task_left);
    return tasks.size() + idles;
  }
};

int main(int argc, char *argv[]) {
  std::vector<char> task1 = {'A', 'A', 'A', 'B', 'B', 'B'};
  std::vector<char> task2 = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'E', 'E', 'F', 'F', 'G', 'G'};
  std::vector<char> task3 = {'A', 'C', 'C', 'C', 'E', 'E', 'E'};
  if (Solution::leastInterval(task1, 2) != 8) {
    throw std::runtime_error("error 1");
  }
  if (Solution::leastInterval(task2, 3) != 13) {
    throw std::runtime_error("error 2");
  }
  if (Solution::leastInterval(task3, 2) != 8) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
