//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Meeting Rooms II
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * Example 1:
 *
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: 1
 */

#include <queue>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  static int minMeetingRooms(std::vector<Interval> &intervals) {
    std::sort(intervals.begin(),
              intervals.end(),
              [](const Interval &a, const Interval &b) { return a.start < b.start; });
    std::priority_queue<int, std::vector<int>, std::greater<int>> rooms;
    for (auto &interval : intervals) {
      if (!rooms.empty() && rooms.top() <= interval.start) {
        rooms.pop();
      }
      rooms.push(interval.end);
    }
    return rooms.size();
  }
};

int main(int argc, char *argv[]) {
  std::vector<Interval> vec1 = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
  std::vector<Interval> vec2 = {Interval(7, 10), Interval(2, 4)};
  if (Solution::minMeetingRooms(vec1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::minMeetingRooms(vec2) != 1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
