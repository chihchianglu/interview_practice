//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Bulls and Cows
 *
 * You are playing the following Bulls and Cows game with your friend:
 * You write down a number and ask your friend to guess what the number is.
 * Each time your friend makes a guess, you provide a hint that indicates
 * how many digits in said guess match your secret number exactly in both
 * digit and position (called "bulls") and how many digits match the secret
 * number but locate in the wrong position (called "cows"). Your friend will
 * use successive guesses and hints to eventually derive the secret number.
 *
 * Write a function to return a hint according to the secret number and friend's
 guess, use A to indicate the bulls and * B to indicate the cows.
 *
 * Please note that both secret number and friend's guess may contain duplicate digits.
 *
 * Example 1:
 *
 * Input: secret = "1807", guess = "7810"
 *
 * Output: "1A3B"
 *
 * Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
 * Example 2:
 *
 * Input: secret = "1123", guess = "0111"
 *
 * Output: "1A1B"
 *
 * Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
 * Note: You may assume that the secret number and your friend's guess only contain
 * digits, and their lengths are always equal.
 */

#include <string>
#include <vector>
#include <stdexcept>

// 其实可以用一次循环就搞定的，在处理不是bulls的位置时，我们看如果secret当前位置数字的映射值小于0，则表示其在guess中出现过，
// cows自增1，然后映射值加1，如果guess当前位置的数字的映射值大于0，则表示其在secret中出现过，cows自增1，然后映射值减1
class Solution {
 public:
  static std::string getHint(std::string secret, std::string guess) {
    std::vector<int> m(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++bulls;
      } else {
        if (m[secret[i] - '0']++ < 0) {
          ++cows;
        }
        if (m[guess[i] - '0']-- > 0) {
          ++cows;
        }
      }
    }
    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }
};

int main(int argc, char *argv[]) {
  if (Solution::getHint("1807", "7810") != "1A3B") {
    std::runtime_error("error 1");
  }
  if (Solution::getHint("1123", "0111") != "1A1B") {
    std::runtime_error("error 2");
  }
  return 0;
}
