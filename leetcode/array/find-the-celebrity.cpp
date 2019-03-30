//
// Created by Lu, Chih-chiang on 2018-12-29.
//

/**
 * Find the Celebrity
 *
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity.
 * The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
 *
 * Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do
 * is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the
 * celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
 *
 * You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int
 * findCelebrity(n), your function should minimize the number of calls to knows.
 *
 * Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a
 * celebrity in the party. If there is no celebrity, return -1.
 */

#include <stdexcept>

class Solution {
 public:
  static bool knows(int a, int b) {
    return true;
  }
  static int findCelebrity(int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (knows(res, i)) {
        res = i;
      }
    }
    // no celebrity check
    for (int i = 0; i < n; ++i) {
      if (res != i && (knows(res, i) || !knows(i, res))) {
        return -1;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
