//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * Read N Characters Given Read4 II - Call multiple times
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3
 * characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from
 * the file.
 *
 * Note:
 * The read function may be called multiple times.
 *
 * Example 1:
 *
 * Given buf = "abc"
 * read("abc", 1) // returns "a"
 * read("abc", 2); // returns "bc"
 * read("abc", 1); // returns ""
 *
 * Example 2:
 *
 * Given buf = "abc"
 * read("abc", 4) // returns "abc"
 * read("abc", 1); // returns ""
 */

#include <cstring>

// Forward declaration of the read4 API.
int read4(char *buf) {
  return 4;
}

class Solution {
 public:
  Solution() : readPos(0), writePos(0) {
    std::memset(buff, 0, sizeof(buff));
  }

  // focus on this one
  int read_v1(char *buf, int n) {
    for (int i = 0; i < n; ++i) {
      if (readPos == writePos) {
        writePos = read4(buff);
        readPos = 0;
        if (writePos == 0) return i;
      }
      buf[i] = buff[readPos++];
    }
    return n;
  }
  int read(char *buf, int n) {
    int i = 0;
    while (i < n && (readPos < writePos || (readPos = 0) < (writePos = read4(buff))))
      buf[i++] = buff[readPos++];
    return i;
  }
 private:
  int readPos;
  int writePos;
  char buff[4];
};

int main(int argc, char *argv[]) {
  return 0;
}
