//
// Created by Lu, Chih-chiang on 2019-02-03.
//

/**
 * Design Hit Counter
 *
 * Design a hit counter which counts the number of hits received in the past 5 minutes.
 *
 * Each function accepts a timestamp parameter (in seconds granularity) and you may assume that
 * calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing).
 * You may assume that the earliest timestamp starts at 1.
 *
 * It is possible that several hits arrive roughly at the same time.
 *
 * Example:
 * HitCounter counter = new HitCounter();
 *
 * // hit at timestamp 1.
 * counter.hit(1);
 *
 * // hit at timestamp 2.
 * counter.hit(2);
 *
 * // hit at timestamp 3.
 * counter.hit(3);
 *
 * // get hits at timestamp 4, should return 3.
 * counter.getHits(4);
 *
 * // hit at timestamp 300.
 * counter.hit(300);
 *
 * // get hits at timestamp 300, should return 4.
 * counter.getHits(300);
 *
 * // get hits at timestamp 301, should return 3.
 * counter.getHits(301);
 *
 * Follow up:
 * What if the number of hits per second could be very large? Does your design scale?
 *
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */

#include <vector>
#include <stdexcept>

// easiest way is to push every hit into queue when hit(), and update the queue when getHits()
// however, if 1million hits at the same timestamp, we run out of memory
// this solution solves it
class HitCounter {
 public:
  /** Initialize your data structure here. */
  HitCounter() : hits_(300, 0), timestamps_(300, 0) {}

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    int idx = timestamp % 300;
    if (timestamps_[idx] != timestamp) {
      timestamps_[idx] = timestamp;
      hits_[idx] = 1;
    } else {
      ++hits_[idx];
    }
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    int res = 0;
    for (int i = 0; i < 300; ++i) {
      if (timestamp - timestamps_[i] < 300) {
        res += hits_[i];
      }
    }
    return res;
  }

 private:
  std::vector<int> hits_;
  std::vector<int> timestamps_;
};

int main(int argc, char *argv[]) {
  HitCounter *obj = new HitCounter();
  obj->hit(1);
  obj->hit(2);
  obj->hit(3);
  if (obj->getHits(4) != 3) {
    throw std::runtime_error("error 1");
  }
  obj->hit(300);
  if (obj->getHits(300) != 4) {
    throw std::runtime_error("error 2");
  }
  if (obj->getHits(301) != 3) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
