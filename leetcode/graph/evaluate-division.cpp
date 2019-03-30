//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Equations are given in the format A / B = k, where A and B are variables represented as strings,
 * and k is a real number (floating point number). Given some queries, return the answers.
 *
 * If the answer does not exist, return -1.0.
 *
 * Example:
 * Given a / b = 2.0, b / c = 3.0.
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 * The input is: vector<pair<string, string>> equations, vector<double>& values,
 * vector<pair<string, string>> queries , where equations.size() == values.size(),
 * and the values are positive. This represents the equations. Return vector<double>.
 *
 * According to the example above:
 *
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 *
 * The input is always valid. You may assume that evaluating the queries will result in no division
 * by zero and there is no contradiction.
 */

#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

// 这道题作为第四次编程比赛的压轴题，感觉还是挺有难度的，个人感觉难度应该设为hard比较合理。
// 这道题已知条件中给了一些除法等式，然后给了另外一些除法等式，问我们能不能根据已知条件求出结果，不能求出来的用-1表示。
// 问题本身是很简单的数学问题，但是写代码来自动实现就需要我们用正确的数据结构和算法，通过观察题目中的例子，
// 我们可以看出如果需要分析的除法式的除数和被除数如果其中任意一个没有在已知条件中出现过，那么返回结果-1，
// 所以我们在分析已知条件的时候，可以使用set来记录所有出现过的字符串，然后我们在分析其他除法式的时候，可以使用递归来做。
// 通过分析得出，不能直接由已知条件得到的情况主要有下面三种：
// 1) 已知: a / b = 2, b / c = 3， 求 a / c
// 2) 已知: a / c = 2, b / c = 3， 求 a / b
// 3) 已知: a / b = 2, a / c = 3， 求 b / c
// 虽然有三种情况，但其实后两种情况都可以转换为第一种情况，对于每个已知条件，我们将其翻转一下也存起来，那么对于对于上面美中情况，
// 就有四个已知条件了：
// 1) 已知: a / b = 2，b / a = 1/2，b / c = 3，c / b = 1/3，求 a / c
// 2) 已知: a / c = 2，c / a = 1/2，b / c = 3，c / b = 1/3，求 a / b
// 3) 已知: a / b = 2，b / a = 1/2，a / c = 3，c / a = 1/3，求 b / c
// 我们发现，第二种和第三种情况也能转化为第一种情况，只需将上面加粗的两个条件相乘即可。对于每一个需要解析的表达式，
// 我们需要一个HashSet来记录已经访问过的表达式，然后对其调用递归函数。在递归函数中，我们在HashMap中快速查找该表达式，
// 如果跟某一个已知表达式相等，直接返回结果。如果没有的话，那么就需要间接寻找了，我们在HashMap中遍历跟解析式中分子相同的已知条件，
// 跳过之前已经遍历过的，否则就加入visited数组，然后再对其调用递归函数，如果返回值是正数，则乘以当前已知条件的值返回，
// 就类似上面的情况一，相乘以后b就消掉了。如果已知找不到解，最后就返回-1
class Solution {
 public:
  // dfs
  static double dfs_helper(std::string num,
                           std::string den,
                           std::unordered_set<std::string> &visited,
                           std::unordered_map<std::string, std::unordered_map<std::string, double>> &mapping) {
    if (mapping[num].count(den)) {
      return mapping[num][den];
    }
    for (auto &tmp_den : mapping[num]) {
      if (visited.count(tmp_den.first)) {
        continue;
      }
      visited.insert(tmp_den.first);
      double val = dfs_helper(tmp_den.first, den, visited, mapping);
      if (val > 0.0) {
        return val * tmp_den.second;
      }
    }
    return -1.0;
  }
  static std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string>> equations,
                                          std::vector<double> &values,
                                          std::vector<std::pair<std::string, std::string>> queries) {
    std::vector<double> res;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> mapping;
    for (int i = 0; i < equations.size(); ++i) {
      mapping[equations[i].first].emplace(equations[i].second, values[i]);
      mapping[equations[i].second].emplace(equations[i].first, 1 / values[i]);
    }
    for (auto &query : queries) {
      std::unordered_set<std::string> visited;
      double val = dfs_helper(query.first, query.second, visited, mapping);
      res.push_back(val > 0.0 ? val : -1.0);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<double> values = {2.0, 3.0};
  std::vector<double> out = {6.0, 0.5, -1.0, 1.0, -1.0};
  if (Solution::calcEquation({{"a", "b"}, {"b", "c"}},
                             values,
                             {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"X", "x"}}) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
