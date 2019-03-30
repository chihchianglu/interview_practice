//
// Created by Lu, Chih-chiang on 2019-01-14.
//

/**
 * Select a random number from stream, with O(1) space
 *
 * Given a stream of numbers, generate a random number from the stream.
 * You are allowed to use only O(1) space and the input is in the form of stream,
 * so can’t store the previously seen numbers.
 */

/**
 * Your Solution will be called like this:
 * var sol = new Solution();
 * var stream = [1, 2, 3, 4];
 * for (let i = 0; i < stream.length; i++) {
 *   console.log("Random number from first " + (i+1) +
 *     " numbers is " + sol.selectRandom(stream[i]));
 * }
 */

#include <vector>
#include <stdexcept>

int selectRandom(int x) {
  static int res;
  static int count = 0;
  ++count;

  // If this is the first element from stream, return it
  if (count == 1) {
    res = x;
  } else {
    // Generate a random number from 0 to count - 1
    int target = std::rand() % count;
    // Replace the prev random number with new number with 1/count probability
    if (target == count - 1) {
      res = x;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  std::vector<int> out = {1, 2, 2, 2, 2, 2, 7, 7, 9, 9, 9, 9};

  for (int i = 0; i < vec.size(); ++i) {
    if (selectRandom(vec[i]) != out[i]) {
      throw std::runtime_error("error");
    }
  }

  return 0;
}
