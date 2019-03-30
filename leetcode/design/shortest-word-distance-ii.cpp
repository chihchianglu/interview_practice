//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * Shortest Word Distance II
 *
 * Design a class which receives a list of words in the constructor, and implements a method that takes two words word1
 * and word2 and return the shortest distance between these two words in the list. Your method will be called
 * repeatedly many times with different parameters.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 *
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

#include <limits>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class WordDistance_v1 {
 public:
  WordDistance_v1(std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); ++i) {
      m_[words[i]].push_back(i);
    }
  }

  // O(MN)
  int shortest(std::string word1, std::string word2) {
    int res = std::numeric_limits<int>::max();
    for (int i = 0; i < m_[word1].size(); ++i) {
      for (int j = 0; j < m_[word2].size(); ++j) {
        res = std::min(res, std::abs(m_[word1][i] - m_[word2][j]));
      }
    }
    return res;
  }

 private:
  std::unordered_map<std::string, std::vector<int>> m_;
};

// 我们可以优化上述的代码，使查询的复杂度由上面的O(MN)变为O(M+N)，其中M和N为两个单词的长度，
// 我们需要两个指针i和j来指向位置数组中的某个位置，开始初始化都为0，然后比较位置数组中的数字，
// 将较小的一个的指针向后移动一位，直至其中一个数组遍历完成即可，
class WordDistance {
 public:
  WordDistance(std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); ++i) {
      m_[words[i]].push_back(i);
    }
  }

  // O(M+N)
  int shortest(std::string word1, std::string word2) {
    int i = 0, j = 0, res = std::numeric_limits<int>::max();
    while (i < m_[word1].size() && j < m_[word2].size()) {
      res = std::min(res, std::abs(m_[word1][i] - m_[word2][j]));
      m_[word1][i] < m_[word2][j] ? ++i : ++j;
    }
    return res;
  }

 private:
  std::unordered_map<std::string, std::vector<int> > m_;
};

int main(int argc, char *argv[]) {
  std::vector<std::string> words = {"practice", "makes", "perfect", "coding", "makes"};
  WordDistance wd(words);
  if (wd.shortest("coding", "practice") != 3) {
    throw std::runtime_error("error 1");
  }
  if (wd.shortest("makes", "coding") != 1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
