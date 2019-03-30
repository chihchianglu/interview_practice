//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs.
 * The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction
 * means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence
 * so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence
 * that can be reconstructed from seqs and it is the org sequence.
 *
 * Example 1:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 *
 * Output:
 * false
 *
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid
 * sequence that can be reconstructed.
 * Example 2:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 *
 * Output:
 * false
 *
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 * Example 3:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 *
 * Output:
 * true
 *
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
 * Example 4:
 *
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 *
 * Output:
 * true
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  static bool sequenceReconstruction(std::vector<int> &org, std::vector<std::vector<int>> &seqs) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::unordered_map<int, int> in_degree;
    for (auto &seq : seqs) {
      for (int i = 1; i < seq.size(); ++i) {
        // only increase in_degree once
        if (!graph[seq[i - 1]].count(seq[i])) {
          ++in_degree[seq[i]];
        }
        graph[seq[i - 1]].insert(seq[i]);
      }
    }

    std::queue<int> q;
    std::vector<int> out;
    for (auto &g : graph) {
      if (!in_degree[g.first]) {
        q.push(g.first);
        out.push_back(g.first);
      }
    }

    while (!q.empty()) {
      if (q.size() != 1) {
        return false; // non-unique seq!!!
      }

      int cur = q.front();
      q.pop();

      for (auto &next : graph[cur]) {
        if (--in_degree[next] == 0) {
          q.push(next);
          out.push_back(next);
        }
      }
    }
    return out == org; // has to be unique seq!!!
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> org1 = {1, 2, 3};
  std::vector<int> org2 = {1, 2, 3};
  std::vector<int> org3 = {1, 2, 3};
  std::vector<int> org4 = {4, 1, 5, 2, 6, 3};
  std::vector<std::vector<int>> seqs1 = {{1, 2}, {1, 3}};
  std::vector<std::vector<int>> seqs2 = {{1, 2}};
  std::vector<std::vector<int>> seqs3 = {{1, 2}, {1, 3}, {2, 3}};
  std::vector<std::vector<int>> seqs4 = {{5, 2, 6, 3}, {4, 1, 5, 2}};

  if (Solution::sequenceReconstruction(org1, seqs1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::sequenceReconstruction(org2, seqs2)) {
    throw std::runtime_error("error 2");
  }
  if (!Solution::sequenceReconstruction(org3, seqs3)) {
    throw std::runtime_error("error 3");
  }
  if (!Solution::sequenceReconstruction(org4, seqs4)) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
