//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * Shuffle an Array
 *
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  Solution(std::vector<int> nums) : vec_(nums) {}

  /** Resets the array to its original configuration and return it. */
  std::vector<int> reset() {
    return vec_;
  }

  /** Returns a random shuffling of the array. */
  std::vector<int> shuffle() { // Knuth-shuffle
    std::vector<int> res = vec_;
    int n = res.size();
    for (int i = 0; i < n; ++i) {
      int j = std::rand() % (i + 1);
      std::swap(res[i], res[j]);
    }
    return res;
  }
 private:
  std::vector<int> vec_;
};

int main(int argc, char *argv[]) {
  return 0;
}
