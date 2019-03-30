//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * Read N Characters Given Read4
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3
 * characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from
 * the file.
 *
 * Example 1:
 *
 * Input: buf = "abc", n = 4
 * Output: "abc"
 * Explanation: The actual number of characters read is 3, which is "abc".
 *
 * Example 2:
 *
 * Input: buf = "abcde", n = 5
 * Output: "abcde"
 *
 * Note:
 * The read function will only be called once for each test case.
 */

#include <algorithm>

// Forward declaration of the read4 API.
int read4(char *buf) {
  return 4;
}

class Solution {
 public:
  // focus on this one
  int read(char *buf, int n) {
    int res = 0;
    for (int i = 0; i <= n / 4; ++i) {
      int cur = read4(buf + res);
      if (cur == 0) {
        break;
      }
      res += cur;
    }
    return std::min(res, n);
  }
  int read_recursion(char *buf, int n) {
    int r = read4(buf);
    if (r >= n) { // eof for buf, buf.size() >= n
      return n;
    } else if (r < 4) { // eof for buf, buf.size() < n
      return r;
    } else {
      return 4 + read(buf + 4, n - 4);
    }
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
