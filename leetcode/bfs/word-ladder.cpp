//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * Word Ladder
 *
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * 1. Only one letter can be changed at a time.
 * 2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 *
 * - All words have the same length.
 * - All words contain only lowercase alphabetic characters.
 * - You may assume no duplicates in the word list.
 * - You may assume beginWord and endWord are non-empty and are not the same.
 *
 * Example 1:
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Example 2:
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */

#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  static int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    std::unordered_set<std::string> word_set(wordList.begin(), wordList.end());
    if (!word_set.count(endWord)) {
      return 0;
    }
    std::queue<std::string> q{{beginWord}};
    int res = 0;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) { // check 1 layer at a time
        std::string word = q.front();
        q.pop();
        if (word == endWord) {
          return ++res;
        }
        for (int j = 0; j < word.size(); ++j) {
          std::string new_word = word;
          char ch = new_word[j];
          for (char c = 'a'; c < 'z'; ++c) {
            if (ch != c) {
              new_word[j] = c;
              if (word_set.count(new_word)) {
                q.push(new_word);
                word_set.erase(new_word);
              }
            }
          }
        }
      }
      ++res;
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> in_1 = {"hot", "dot", "dog", "lot", "log", "cog"};
  std::vector<std::string> in_2 = {"hot", "dot", "dog", "lot", "log"};
  if (Solution::ladderLength("hit", "cog", in_1) != 5) {
    throw std::runtime_error("error 1");
  }
  if (Solution::ladderLength("hit", "cog", in_2) != 0) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
