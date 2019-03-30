//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Logger Rate Limiter
 *
 * Design a logger system that receive stream of messages along with its timestamps,
 * each message should be printed if and only if it is not printed in the last 10 seconds.
 *
 * Given a message and a timestamp (in seconds granularity),
 * return true if the message should be printed in the given timestamp, otherwise returns false.
 *
 * It is possible that several messages arrive roughly at the same time.
 *
 * Example:
 *
 * Logger logger = new Logger();
 *
 * // logging string "foo" at timestamp 1
 * logger.shouldPrintMessage(1, "foo"); returns true;
 *
 * // logging string "bar" at timestamp 2
 * logger.shouldPrintMessage(2,"bar"); returns true;
 *
 * // logging string "foo" at timestamp 3
 * logger.shouldPrintMessage(3,"foo"); returns false;
 *
 * // logging string "bar" at timestamp 8
 * logger.shouldPrintMessage(8,"bar"); returns false;
 *
 * // logging string "foo" at timestamp 10
 * logger.shouldPrintMessage(10,"foo"); returns false;
 *
 * // logging string "foo" at timestamp 11
 * logger.shouldPrintMessage(11,"foo"); returns true;
 */

#include <string>
#include <stdexcept>
#include <unordered_map>

class Logger {
 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, std::string message) {
    if (m_.count(message)) {
      if (timestamp >= m_[message] + 10) {
        m_[message] = timestamp;
      } else {
        return false;
      }
    } else {
      m_[message] = timestamp;
    }
    return true;
  }

 private:
  std::unordered_map<std::string, int> m_;
};

int main(int argc, char *argv[]) {
  Logger *logger = new Logger();
  if (!logger->shouldPrintMessage(1, "foo")) {
    throw std::runtime_error("error 1");
  }
  if (!logger->shouldPrintMessage(2, "bar")) {
    throw std::runtime_error("error 2");
  }
  if (logger->shouldPrintMessage(3, "foo")) {
    throw std::runtime_error("error 3");
  }
  if (logger->shouldPrintMessage(8, "bar")) {
    throw std::runtime_error("error 4");
  }
  if (logger->shouldPrintMessage(10, "foo")) {
    throw std::runtime_error("error 5");
  }
  if (!logger->shouldPrintMessage(11, "foo")) {
    throw std::runtime_error("error 6");
  }
  return 0;
}
