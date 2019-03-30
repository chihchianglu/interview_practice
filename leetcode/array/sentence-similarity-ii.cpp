//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Sentence Similarity II
 *
 * Given two sentences words1, words2 (each represented as an array of strings), and a list of similar
 * word pairs pairs, determine if two sentences are similar.
 *
 * For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar,
 * if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"],
 * ["skills","talent"]].
 *
 * Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and
 * "fine" and "good" are similar, then "great" and "fine" are similar.
 *
 * Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and
 * "great" being similar.
 *
 * Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 =
 * ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
 *
 * Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 =
 * ["great"] can never be similar to words2 = ["doubleplus","good"].
 *
 * Note:
 *
 * The length of words1 and words2 will not exceed 1000.
 * The length of pairs will not exceed 2000.
 * The length of each pairs[i] will be 2.
 * The length of each words[i] and pairs[i][j] will be in the range [1, 20].
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static std::string find(std::unordered_map<std::string, std::string> &map, std::string word) {
    if (map.find(word) == map.end()) {
      map[word] = word;
    }
    return word == map[word] ? word : find(map, map[word]);
  }
  static bool areSentencesSimilarTwo(std::vector<std::string> &words1,
                                     std::vector<std::string> &words2,
                                     std::vector<std::pair<std::string, std::string>> pairs) {
    if (words1.size() != words2.size()) {
      return false;
    }
    int n = words1.size();
    std::unordered_map<std::string, std::string> map;
    for (auto &pair : pairs) {
      std::string parent1 = find(map, pair.first);
      std::string parent2 = find(map, pair.second);
      if (parent1 != parent2) {
        map[parent1] = parent2;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (words1[i] != words2[i] && find(map, words1[i]) != find(map, words2[i])) {
        return false;
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> ex1_word1 = {"great"};
  std::vector<std::string> ex2_word1 = {"great", "acting", "skills"};

  std::vector<std::string> ex1_word2 = {"great"};
  std::vector<std::string> ex2_word2 = {"fine", "drama", "talent"};
  std::vector<std::string> ex3_word2 = {"doubleplus", "good"};

  std::vector<std::pair<std::string, std::string>> ex1_pairs = {};
  std::vector<std::pair<std::string, std::string>>
      ex2_pairs = {{"great", "good"}, {"fine", "good"}, {"acting", "drama"}, {"skills", "talent"}};
  std::vector<std::pair<std::string, std::string>> ex3_pairs = {{"great", "good"}};

  if (!Solution::areSentencesSimilarTwo(ex1_word1, ex1_word2, ex1_pairs)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::areSentencesSimilarTwo(ex2_word1, ex2_word2, ex2_pairs)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::areSentencesSimilarTwo(ex1_word1, ex3_word2, ex3_pairs)) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
