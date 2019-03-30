//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Group Anagrams
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

// 这道题让我们群组给定字符串集中所有的错位词，所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，
// 比如abc，bac, cba等它们就互为错位词，那么我们如何判断两者是否是错位词呢，我们发现如果把错位词的字符顺序重新排列，
// 那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法，由于错位词重新排序后都会得到相同的字符串，我们以此作为key，
// 将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结果res中即可
class Solution {
 public:
  static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> m;
    for (auto str : strs) {
      std::string tmp = str;
      std::sort(tmp.begin(), tmp.end());
      m[tmp].push_back(str);
    }
    for (auto a : m) {
      res.push_back(a.second);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> out{{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
  if (Solution::groupAnagrams(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
