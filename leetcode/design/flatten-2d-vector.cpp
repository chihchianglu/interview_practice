//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Flatten 2D Vector
 *
 * Implement an iterator to flatten a 2d vector.
 *
 * Example:
 *
 * Input: 2d vector =
 * [
 *   [1,2],
 *   [3],
 *   [4,5,6]
 * ]
 * Output: [1,2,3,4,5,6]
 * Explanation: By calling next repeatedly until hasNext returns false,
 *              the order of elements returned by next should be: [1,2,3,4,5,6].
 */

#include <vector>

class Vector2D_v1 {
 public:
  Vector2D_v1(std::vector<std::vector<int>> &vec2d) : idx_(0) {
    for (auto &v : vec2d) {
      vec_.insert(vec_.end(), v.begin(), v.end());
    }
  }
  int next() {
    return vec_[idx_++];
  }
  bool hasNext() {
    return idx_ < vec_.size();
  }
 private:
  int idx_;
  std::vector<int> vec_;
};

class Vector2D {
 public:
  Vector2D(std::vector<std::vector<int>> &vec2d) : y_(0) {
    x_itr_ = vec2d.begin();
    end_itr_ = vec2d.end();
  }
  int next() {
    return (*x_itr_)[y_++];
  }
  bool hasNext() {
    while (x_itr_ != end_itr_ && y_ == (*x_itr_).size()) {
      ++x_itr_;
      y_ = 0;
    }
    return x_itr_ != end_itr_;
  }
 private:
  std::vector<std::vector<int>>::iterator x_itr_, end_itr_;
  int y_;
};

int main(int argc, char *argv[]) {
  return 0;
}
