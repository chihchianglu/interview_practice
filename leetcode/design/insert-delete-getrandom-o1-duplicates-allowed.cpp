//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Insert Delete GetRandom O(1) - Duplicates Allowed
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * Note: Duplicate elements are allowed.
 *
 * 1. insert(val): Inserts an item val to the set if not already present.
 * 2. remove(val): Removes an item val from the set if present.
 * 3. getRandom: Returns a random element from current set of elements.
 *    Each element must have the same probability of being  * returned.
 *
 * 1. insert(val): Inserts an item val to the collection.
 * 2. remove(val): Removes an item val from the collection if present.
 * 3. getRandom: Returns a random element from current collection of elements.
 *               The probability of each element being returned is linearly related to the number of same value
 *               the collection contains.
 *
 * Example:
 *
 * // Init an empty collection.
 * RandomizedCollection collection = new RandomizedCollection();
 *
 * // Inserts 1 to the collection. Returns true as the collection did not contain 1.
 * collection.insert(1);
 *
 * // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
 * collection.insert(1);
 *
 * // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
 * collection.insert(2);
 *
 * // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
 * collection.getRandom();
 *
 * // Removes 1 from the collection, returns true. Collection now contains [1,2].
 * collection.remove(1);
 */

#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

class RandomizedCollection {
 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    nums_.push_back(val);
    m_[val].insert(nums_.size() - 1);
    return m_[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    if (m_.count(val) == 0) {
      return false;
    }
    int idx = *m_[val].begin();
    m_[val].erase(idx);
    if (nums_.size() - 1 != idx) {
      int last = nums_.back();
      nums_[idx] = last;
      m_[last].erase(nums_.size() - 1);
      m_[last].insert(idx);
    }
    nums_.pop_back();

    if (m_[val].empty()) {
      m_.erase(val);
    }
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    return nums_[std::rand() % nums_.size()];
  }

 private:
  std::vector<int> nums_;
  std::unordered_map<int, std::unordered_set<int>> m_;
};

int main(int argc, char *argv[]) {
  RandomizedCollection rc;
  if (!rc.insert(1)) {
    throw std::runtime_error("error 1");
  }
  if (!rc.insert(3)) {
    throw std::runtime_error("error 2");
  }
  if (rc.insert(1)) {
    throw std::runtime_error("error 3");
  }
  if (!rc.remove(3)) {
    throw std::runtime_error("error 4");
  }
  if (!rc.remove(1)) {
    throw std::runtime_error("error 5");
  }
  if (!rc.remove(1)) {
    throw std::runtime_error("error 6");
  }
  if (rc.remove(1)) {
    throw std::runtime_error("error 7");
  }
  return 0;
}
