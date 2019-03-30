//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Employee Free Time
 *
 * We are given a list schedule of employees, which represents the working time for each employee.
 *
 * Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
 *
 * Return the list of finite intervals representing common, positive-length free time for all employees,
 * also in sorted order.
 *
 * Example 1:
 *
 * Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 * Output: [[3,4]]
 *
 * Explanation:
 *
 * There are a total of three employees, and all common
 * free time intervals would be [-inf, 1], [3, 4], [10, inf].
 * We discard any intervals that contain inf as they aren't finite.
 *
 * Example 2:
 *
 * Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
 * Output: [[5,6],[7,9]]
 *
 * (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals,
 * not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0]
 * is not defined.)
 *
 * Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
 */

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  static std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>> &schedule) {
    std::vector<Interval> res, tmp;
    for (auto &interval : schedule) {
      tmp.insert(tmp.end(), interval.begin(), interval.end());
    }
    std::sort(tmp.begin(), tmp.end(), [](Interval &a, Interval &b) { return a.start < b.start; });

    Interval cur = tmp[0];
    for (Interval interval : tmp) {
      if (cur.end < interval.start) {
        res.push_back(Interval(cur.end, interval.start));
        cur = interval;
      } else {
        if (cur.end < interval.end) {
          cur = interval;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Interval ex1_1(1, 2);
  Interval ex1_2(5, 6);
  Interval ex1_3(1, 3);
  Interval ex1_4(4, 10);
  Interval ex2_1(1, 3);
  Interval ex2_2(6, 7);
  Interval ex2_3(2, 4);
  Interval ex2_4(2, 5);
  Interval ex2_5(9, 12);
  Interval ans1_1(3, 4);
  Interval ans2_1(5, 6);
  Interval ans2_2(7, 9);
  std::vector<std::vector<Interval>> vec1 = {{ex1_1, ex1_2}, {ex1_3}, {ex1_4}};
  std::vector<std::vector<Interval>> vec2 = {{ex2_1, ex2_2}, {ex2_3}, {ex2_4, ex2_5}};
  std::vector<Interval> out1 = {ans1_1};
  std::vector<Interval> out2 = {ans2_1, ans2_2};
  auto out_ans_1 = Solution::employeeFreeTime(vec1);
  for (int i = 0; i < out_ans_1.size(); ++i) {
    if (out_ans_1[i].start != out1[i].start || out_ans_1[i].end != out1[i].end) {
      throw std::runtime_error("error 1");
    }
  }
  auto out_ans_2 = Solution::employeeFreeTime(vec2);
  for (int i = 0; i < out_ans_2.size(); ++i) {
    if (out_ans_2[i].start != out2[i].start || out_ans_2[i].end != out2[i].end) {
      throw std::runtime_error("error 2");
    }
  }
  return 0;
}
