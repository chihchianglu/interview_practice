//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Insert Delete GetRandom O(1)
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * 1. insert(val): Inserts an item val to the set if not already present.
 * 2. remove(val): Removes an item val from the set if present.
 * 3. getRandom: Returns a random element from current set of elements.
 *    Each element must have the same probability of being  * returned.
 *
 * Example:
 *
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 */

#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <unordered_map>

// map[val] = idx
// vec[idx] = val
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (m_.count(val)) {
      return false;
    }
    nums_.push_back(val);
    m_[val] = nums_.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (!m_.count(val)) {
      return false;
    }
    // example: nums=[1, 2, 3, 4, 5], val = 3
    // 1. m[5] = m[3] = 2(idx)
    // 2. nums[2] = 5
    // 3. remove nums[4] && m[3]
    int last = nums_.back();
    m_[last] = m_[val];
    nums_[m_[val]] = last;
    nums_.pop_back();
    m_.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums_[std::rand() % nums_.size()];
  }
 private:
  std::vector<int> nums_;
  std::unordered_map<int, int> m_;
};

int main(int argc, char *argv[]) {
  RandomizedSet rs;
  if (!rs.insert(1)) {
    throw std::runtime_error("error 1");
  }
  if (!rs.insert(2)) {
    throw std::runtime_error("error 2");
  }
  if (!rs.insert(3)) {
    throw std::runtime_error("error 3");
  }
  if (!rs.remove(2)) {
    throw std::runtime_error("error 4");
  }
  if (!rs.remove(1)) {
    throw std::runtime_error("error 5");
  }
  if (!rs.remove(3)) {
    throw std::runtime_error("error 6");
  }
  if (rs.remove(1)) {
    throw std::runtime_error("error 7");
  }
  return 0;
}
