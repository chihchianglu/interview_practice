//
// Created by Lu, Chih-chiang on 2019-02-07.
//

/**
 * My Calendar II
 *
 * Implement a MyCalendarTwo class to store your events. A new event can be added if adding
 * the event will not cause a triple booking.
 *
 * Your class will have one method, book(int start, int end). Formally, this represents a booking
 * on the half open interval [start, end), the range of real numbers x such that start <= x < end.
 *
 * A triple booking happens when three events have some non-empty intersection (ie., there is some
 * time that is common to all 3 events.)
 *
 * For each call to the method MyCalendar.book, return true if the event can be added to the calendar
 * successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 *
 * Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
 *
 * Example 1:
 *
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(50, 60); // returns true
 * MyCalendar.book(10, 40); // returns true
 * MyCalendar.book(5, 15);  // returns false
 * MyCalendar.book(5, 10);  // returns true
 * MyCalendar.book(25, 55); // returns true
 *
 * Explanation:
 *
 * The first two events can be booked.  The third event can be double booked.
 * The fourth event (5, 15) can't be booked, because it would result in a triple booking.
 * The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
 * The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
 * the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
 *
 * Note:
 *
 * The number of calls to MyCalendar.book per test case will be at most 1000.
 * In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
 *
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

#include <set>
#include <stdexcept>

class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto overlap : overlaps_) {
      if (start >= overlap.second || end <= overlap.first) {
        continue;
      } else {
        return false;
      }
    }
    for (auto calendar : calendars_) {
      if (start >= calendar.second || end <= calendar.first) {
        continue;
      } else {
        overlaps_.insert(std::make_pair(std::max(start, calendar.first), std::min(end, calendar.second)));
      }
    }
    calendars_.insert(std::make_pair(start, end));
    return true;
  }
 private:
  std::set<std::pair<int, int>> overlaps_;
  std::set<std::pair<int, int>> calendars_;
};

int main(int argc, char *argv[]) {
  MyCalendarTwo calendar;
  if (!calendar.book(10, 20)) {
    throw std::runtime_error("error 1");
  }
  if (!calendar.book(50, 60)) {
    throw std::runtime_error("error 2");
  }
  if (!calendar.book(10, 40)) {
    throw std::runtime_error("error 3");
  }
  if (calendar.book(5, 15)) {
    throw std::runtime_error("error 4");
  }
  if (!calendar.book(5, 10)) {
    throw std::runtime_error("error 5");
  }
  if (!calendar.book(25, 55)) {
    throw std::runtime_error("error 6");
  }
  return 0;
}
