//
// Created by Lu, Chih-chiang on 2019-02-02.
//

/**
 * Design Compressed String Iterator
 *
 * Design and implement a data structure for a compressed string iterator.
 * It should support the following operations: next and hasNext.
 *
 * The given compressed string will be in the form of each letter followed by a
 * positive integer representing the number of this letter existing in the original uncompressed string.
 *
 * next() - if the original string still has uncompressed characters, return the next letter;
 * Otherwise return a white space.
 * hasNext() - Judge whether there is any letter needs to be uncompressed.
 *
 * Note:
 * Please remember to RESET your class variables declared in StringIterator,
 * as static/class variables are persisted across multiple test cases. Please see here for more details.
 *
 * Example:
 *
 * StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
 *
 * iterator.next(); // return 'L'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 't'
 * iterator.next(); // return 'C'
 * iterator.next(); // return 'o'
 * iterator.next(); // return 'd'
 * iterator.hasNext(); // return true
 * iterator.next(); // return 'e'
 * iterator.hasNext(); // return false
 * iterator.next(); // return ' '
 *
 * Your StringIterator object will be instantiated and called as such:
 * var obj = new StringIterator(compressedString)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */

#include <string>
#include <stdexcept>

class StringIterator {
 public:
  StringIterator(std::string compressedString) : repeat_(0), cur_idx_(0), cur_char_(' '), str_(compressedString) {
    update();
  }

  void update() {
    repeat_ = 0;
    int i = cur_idx_ + 1;
    while (i < str_.size() && str_[i] >= '0' && str_[i] <= '9') {
      repeat_ = repeat_ * 10 + str_[i++] - '0';
    }

    if (!str_.empty()) {
      cur_char_ = str_[cur_idx_];
    }
    cur_idx_ = i;
  }

  char next() {
    --repeat_;
    auto ret = cur_char_;
    if (repeat_ <= 0) {
      update();
    }
    return ret;
  }

  bool hasNext() {
    return repeat_ > 0;
  }

 private:
  int repeat_;
  int cur_idx_;
  char cur_char_;
  std::string str_;
};

int main(int argc, char *argv[]) {
  StringIterator *obj = new StringIterator("L12e2t3C1o2d1e3");
  StringIterator *obj2 = new StringIterator("");
  std::string out1 = "LLLLLLLLLLLLeetttCoodeee";
  std::string out2 = "";
  int count = 0;
  while (obj->hasNext()) {
    if (obj->next() != out1[count++]) {
      throw std::runtime_error("error 1");
    }
  }
  count = 0;
  while (obj2->hasNext()) {
    if (obj2->next() != out2[count++]) {
      throw std::runtime_error("error 2");
    }
  }
  return 0;
}
