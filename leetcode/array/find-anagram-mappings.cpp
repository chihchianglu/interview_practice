//
// Created by Lu, Chih-chiang on 2018-12-29.
//

/**
 * Find Anagram Mappings
 *
 * Given two lists A and B, and B is an anagram of A.
 * B is an anagram of A means B is made by randomizing the order of the elements in A.
 *
 * We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.
 *
 * These lists A and B may contain duplicates. If there are multiple answers, output any of them.
 *
 * For example, given
 *
 * A = [12, 28, 46, 32, 50]
 * B = [50, 12, 32, 46, 28]
 * We should return
 * [1, 4, 3, 2, 0]
 * as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
 * Note:
 *
 * A, B have equal lengths in range [1, 100].
 * A[i], B[i] are integers in range [0, 10^5].
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static std::vector<int> anagramMappings(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> res;
    std::unordered_map<int, int> cache;
    for (int i = 0; i < B.size(); ++i) {
      cache[B[i]] = i;
    }
    for (int i = 0; i < A.size(); ++i) {
      if (cache.count(A[i])) {
        res.push_back(cache[A[i]]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {12, 28, 46, 32, 50};
  std::vector<int> vec2 = {50, 12, 32, 46, 28};
  std::vector<int> out = {1, 4, 3, 2, 0};

  if (Solution::anagramMappings(vec1, vec2) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
