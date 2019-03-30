//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * H-Index
 *
 * Given an array of citations (each citation is a non-negative integer) of a researcher,
 * write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her
 * N papers have at least h citations each, and the other N − h papers have no more than h citations
 * each."
 *
 * Example:
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
 *              received 3, 0, 6, 1, 5 citations respectively.
 *              Since the researcher has 3 papers with at least 3 citations each and the remaining
 *              two with no more than 3 citations each, her h-index is 3.
 * Note: If there are several possible values for h, the maximum one is taken as the h-index.
 */

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

class Solution {
 public:
  static int hIndex(std::vector<int> &citations) {
    int n = citations.size();
    std::sort(citations.begin(), citations.end(), std::greater<int>());
    for (int i = 0; i < n; ++i) {
      if (citations[i] < i + 1) {
        return i;
      }
    }
    return n;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {3, 0, 6, 1, 5};
  if (Solution::hIndex(vec) != 3) {
    throw std::runtime_error("error");
  }
  return 0;
}
