//
// Created by Lu, Chih-chiang on 2018-12-31.
//

/**
 * K Empty Slots
 *
 * There is a garden with N slots. In each slot, there is a flower.
 * The N flowers will bloom one by one in N days.
 * In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
 *
 * Given an array flowers consists of number from 1 to N.
 * Each number in the array represents the place where the flower will open in that day.
 *
 * For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x,
 * where i and x will be in the range from 1 to N.
 *
 * Also given an integer k, you need to output in which day there exists two flowers in the status of blooming,
 * and also the number of flowers between them is k and these flowers are not blooming.
 *
 * If there isn't such day, output -1.
 *
 * Example 1:
 * Input:
 * flowers: [1,3,2]
 * k: 1
 * Output: 2
 * Explanation: In the second day, the first and the third flower have become blooming.
 *
 * Example 2:
 * Input:
 * flowers: [1,2,3]
 * k: 1
 * Output: -1
 *
 * Note:
 * The given array will be in the range [1, 20000].
 */

#include <set>
#include <cmath>
#include <vector>
#include <limits>
#include <stdexcept>

class Solution {
 public:
  static int kEmptySlots_v1(std::vector<int> &flowers, int k) {
    int res = std::numeric_limits<int>::max(), l = 0, r = k + 1, n = flowers.size();
    std::vector<int> days(n, 0);

    for (int i = 0; i < n; ++i) {
      days[flowers[i] - 1] = i + 1;
    }

    for (int i = 0; r < n; ++i) {
      if (days[i] < days[l] || days[i] <= days[r]) {
        if (i == r) {
          res = std::min(res, std::max(days[l], days[r]));
        }
        l = i;
        r = k + 1 + i;
      }
    }
    return res == std::numeric_limits<int>::max() ? -1 : res;
  }
  static int kEmptySlots(std::vector<int> &flowers, int k) {
    std::set<int> s;
    for (int i = 0; i < flowers.size(); ++i) {
      int cur = flowers[i];
      auto it = s.upper_bound(cur);
      if (it != s.end() && *it - cur == k + 1) {
        return i + 1;
      }
      it = s.lower_bound(cur);
      if (it != s.begin() && cur - *(--it) == k + 1) {
        return i + 1;
      }
      s.insert(cur);
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 3, 2};
  std::vector<int> vec2 = {1, 2, 3};

  if (Solution::kEmptySlots_v1(vec1, 1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::kEmptySlots_v1(vec2, 1) != -1) {
    throw std::runtime_error("error 2");
  }

  if (Solution::kEmptySlots(vec1, 1) != 2) {
    throw std::runtime_error("error 3");
  }
  if (Solution::kEmptySlots(vec2, 1) != -1) {
    throw std::runtime_error("error 4");
  }

  return 0;
}
