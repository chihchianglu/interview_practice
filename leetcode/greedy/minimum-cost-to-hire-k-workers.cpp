//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Minimum Cost To Hire K Workers
 *
 * There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].
 * Now we want to hire exactly K workers to form a paid group.
 *
 * When hiring a group of K workers, we must pay them according to the following rules:
 * 1. Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
 * 2. Every worker in the paid group must be paid at least their minimum wage expectation.
 * Return the least amount of money needed to form a paid group satisfying the above conditions.
 *
 * Example 1:
 * Input: quality = [10,20,5], wage = [70,50,30], K = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
 *
 * Example 2:
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately.
 *
 * Note:
 * 1 <= K <= N <= 10000, where N = quality.length = wage.length
 * 1 <= quality[i] <= 10000
 * 1 <= wage[i] <= 10000
 * Answers within 10^-5 of the correct answer will be considered correct.
 */

#include <cmath>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Solution {
 public:
  static double mincostToHireWorkers(std::vector<int> &quality, std::vector<int> &wage, int K) {
    std::vector<std::pair<double, int>> workers;
    for (int i = 0; i < quality.size(); ++i) {
      workers.emplace_back(double(wage[i]) / quality[i], quality[i]);
    }
    std::sort(workers.begin(), workers.end());

    double res = std::numeric_limits<double>::max(), sum = 0.0;
    std::priority_queue<int> max_q;
    for (const auto &worker : workers) {
      sum += worker.second;
      max_q.emplace(worker.second);
      if (max_q.size() > K) {
        sum -= max_q.top();
        max_q.pop();
      }
      if (max_q.size() == K) {
        res = std::min(res, sum * worker.first);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> q1 = {10, 20, 5};
  std::vector<int> w1 = {70, 50, 30};
  std::vector<int> q2 = {3, 1, 10, 10, 1};
  std::vector<int> w2 = {4, 8, 2, 2, 7};
  if (Solution::mincostToHireWorkers(q1, w1, 2) != 105.0) {
    throw std::runtime_error("error 1");
  }
  if (std::ceil(Solution::mincostToHireWorkers(q2, w2, 3)) != 31) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
