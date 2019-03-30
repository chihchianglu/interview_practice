//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Exam Room
 *
 * In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
 *
 * When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.
 * If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the
 * room, then the student sits at seat number 0.)
 *
 * Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what
 * seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves
 * the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
 *
 * Example 1:
 *
 * Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
 * Output: [null,0,9,4,2,null,5]
 *
 * Explanation:
 * ExamRoom(10) -> null
 * seat() -> 0, no one is in the room, then the student sits at seat number 0.
 * seat() -> 9, the student sits at the last seat number 9.
 * seat() -> 4, the student sits at the last seat number 4.
 * seat() -> 2, the student sits at the last seat number 2.
 * leave(4) -> null
 * seat() -> 5, the student sits at the last seat number 5.
 */

#include <set>
#include <stdexcept>

class ExamRoom {
 public:
  ExamRoom(int N) : size_(N) {}

  int seat() {
    int res = 0;
    if (seats_.size()) {
      // find seats
      int idx = 0;
      int max_len = 0;

      // 查看0是否占用
      if (!seats_.count(0)) {
        // 注意，最后的那个位置和0处的距离是不需要除2的
        max_len = *seats_.begin() - 0;
      }
      for (auto it = seats_.begin(); it != seats_.end(); ++it) {
        int len = (*it - idx) / 2;
        if (len > max_len) {
          max_len = len;
          res = (*it + idx) / 2;
        }
        idx = *it;
      }
      // 看最后的位置有没有被占
      if (!seats_.count(size_ - 1)) {
        int len = size_ - 1 - *seats_.rbegin();
        if (len > max_len) {
          max_len = len;
          res = size_ - 1;
        }
      }
    }
    seats_.insert(res);
    return res;
  }

  void leave(int p) {
    seats_.erase(seats_.find(p));
  }

 private:
  int size_;
  std::set<int> seats_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

int main(int argc, char *argv[]) {
  ExamRoom em(10);
  if (em.seat() != 0) {
    throw std::runtime_error("error 1");
  }
  if (em.seat() != 9) {
    throw std::runtime_error("error 2");
  }
  if (em.seat() != 4) {
    throw std::runtime_error("error 3");
  }
  if (em.seat() != 2) {
    throw std::runtime_error("error 4");
  }
  em.leave(4);
  if (em.seat() != 5) {
    throw std::runtime_error("error 5");
  }
  return 0;
}
