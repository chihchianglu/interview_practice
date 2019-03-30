//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Gas Station III
 *
 * A person tries to drive from city A to city B, there are N gas stations between the two cities.
 * An array of {distance, price} is given, the distance is the distance from A, and the price is
 * the gas price at the station.
 *
 * Also, the car's MPG (miles per gallon) and tank size (gallon) is given. In order to reach to city B,
 * try to pay the petrol as less as possible, write a program to return the minimum costs.
 *
 * There are some rules:
 * 1. The car has full-tank of petrol when start
 * 2. At any station, the car always fill up the petrol in full
 * 3. The car always drives with constant MPG
 *
 * If it's impossible to drive to city B, return -1.
 *
 * For example:
 *
 * A            $1       $2   $5    $1      $6   $4        $1         B
 * |------------|--------|----|-----|-------|----|---------|----------|
 * 0           100      140  150   200     330  360       400        500 miles
 *
 * MPG: 10 (miles/gallon)
 * Tank size: 18 (gallon)
 *
 * Your program should return 840
 *
 * Explanation:
 *
 * Stop at 100 mile, cost $1 * 100 to fill full tank
 * Stop at 200 mile, cost $1 * 100
 * Stop at 360 mile, cost $4 * 160
 *
 * Total cost is $840
 *
 * If we stop at 150 mile and 330 mile, although we only need to stop at two stations, but the total cost
 * is 150*5 + (330 - 150) * 6 = $1,830
 */

#include <vector>
#include <numeric>
#include <stdexcept>
class Solution {
 public:
  static int minCost(int totalDistance, int mpg, int tank, std::vector<int> &distances, std::vector<int> &prices) {
    int n = distances.size();
    std::vector<int> dp(n + 2, 0); // min cost at station i
    distances.insert(distances.begin(), 0);
    distances.push_back(totalDistance);
    prices.insert(prices.begin(), 0);
    prices.push_back(0);

    for (int i = 1; i < n + 2; ++i) {
      dp[i] = std::numeric_limits<int>::max();
      for (int j = 0; j < i; ++j) {
        int diff = distances[i] - distances[j];
        if (diff <= mpg * tank) {
          dp[i] = std::min(dp[i], dp[j] + prices[i] * diff);
        }
      }
    }
    return dp[n + 1] < std::numeric_limits<int>::max() ? dp[n + 1] : -1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> distances{100, 140, 150, 200, 330, 360, 400};
  std::vector<int> prices{1, 2, 5, 1, 6, 4, 1};
  if (Solution::minCost(500, 10, 18, distances, prices) != 840) {
    throw std::runtime_error("error");
  }
  return 0;
}
