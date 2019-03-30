//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Design Phone Directory
 *
 * Design a Phone Directory which supports the following operations:
 *
 * get: Provide a number which is not assigned to anyone.
 * check: Check if a number is available or not.
 * release: Recycle or release a number.
 * Example:
 *
 * // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
 * PhoneDirectory directory = new PhoneDirectory(3);
 *
 * // It can return any available phone number. Here we assume it returns 0.
 * directory.get();
 *
 * // Assume it returns 1.
 * directory.get();
 *
 * // The number 2 is available, so return true.
 * directory.check(2);
 *
 * // It returns 2, the only number that is left.
 * directory.get();
 *
 * // The number 2 is no longer available, so return false.
 * directory.check(2);
 *
 * // Release number 2 back to the pool.
 * directory.release(2);
 *
 * // Number 2 is available again, return true.
 * directory.check(2);
 */

#include <vector>
#include <stdexcept>
#include <unordered_set>

class PhoneDirectory {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) : available_nums_(maxNumbers), nums_(maxNumbers, 0), available_(maxNumbers, true) {
    for (int i = 0; i < maxNumbers; ++i) {
      nums_[i] = i;
    }
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (available_nums_ == 0) {
      return -1;
    }
    int res = nums_[--available_nums_];
    available_[res] = false;
    return res;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return available_[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (available_[number]) {
      return;
    }
    nums_[available_nums_++] = number;
    available_[number] = true;
  }
 private:
  int available_nums_;
  std::vector<int> nums_;
  std::vector<bool> available_;
};

class PhoneDirectory_v2 {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory_v2(int maxNumbers) {
    for (int i = 0; i < maxNumbers; ++i) {
      hash_.insert(i);
    }
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (hash_.empty()) {
      return -1;
    }
    int res = *hash_.begin();
    hash_.erase(hash_.begin());
    return res;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return hash_.find(number) != hash_.end();
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (hash_.find(number) != hash_.end()) {
      return;
    }
    hash_.insert(number);
  }
 private:
  std::unordered_set<int> hash_;
};

int main(int argc, char *argv[]) {
  PhoneDirectory *pd = new PhoneDirectory(10);
  PhoneDirectory_v2 *pd2 = new PhoneDirectory_v2(10);

  if (pd->get() != 9) {
    throw std::runtime_error("error 1");
  }
  if (pd->get() != 8) {
    throw std::runtime_error("error 2");
  }
  for (int i = 0; i < 5; ++i) {
    pd->get();
  }
  if (pd->check(3)) {
    throw std::runtime_error("error 3");
  }
  if (!pd->check(2)) {
    throw std::runtime_error("error 4");
  }
  pd->release(9);
  if (pd->get() != 9) {
    throw std::runtime_error("error 5");
  }
  if (pd->check(3)) {
    throw std::runtime_error("error 6");
  }
  if (!pd->check(2)) {
    throw std::runtime_error("error 7");
  }

  if (pd2->get() != 9) {
    throw std::runtime_error("error 8");
  }
  if (pd2->get() != 8) {
    throw std::runtime_error("error 9");
  }
  for (int i = 0; i < 5; ++i) {
    pd2->get();
  }
  if (pd2->check(3)) {
    throw std::runtime_error("error 10");
  }
  if (!pd2->check(2)) {
    throw std::runtime_error("error 11");
  }
  pd2->release(9);
  if (pd2->get() != 9) {
    throw std::runtime_error("error 12");
  }
  if (pd2->check(3)) {
    throw std::runtime_error("error 13");
  }
  if (!pd2->check(2)) {
    throw std::runtime_error("error 14");
  }

  return 0;
}
