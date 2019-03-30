//
// Created by Lu, Chih-chiang on 2019-01-24.
//

/**
 * Cheapest Flights Within K Stops
 *
 * There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
 *
 * Now given all the cities and flights, together with starting city src and the destination dst,
 * your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 *
 * Example 1:
 *
 * Input:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 *
 * Explanation:
 * The graph looks like this:
 *
 *                 0
 *           100 /   \ 500
 *              v     v
 *             1 ----> 2
 *                100
 *
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200.
 *
 * In the above picture, if k is 0, then the answer should be 500. The cheapest price from city 0 to city 2
 * with at most 0 stop costs 500.
 *
 * Solution: Instead of nodes being places, use places and number of stops.
 * We want to find the lowest cost from source to target, which makes Dijkstra's a good candidate algorithm.
 *
 * If we continually extend our potential flightpaths in order of cost, we know once we've reached the
 * destination dst that it was the lowest cost way to get there. This is the idea behind Dijkstra's algorithm.
 */

#include <queue>
#include <limits>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  // bfs
  static int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int K) {
    int res = std::numeric_limits<int>::max(), k_count = 0;
    std::unordered_map<int, std::vector<std::pair<int, int>>> cache; // src -> list of (dst, price)
    std::queue<std::pair<int, int>> queue({{src, 0}}); // target src -> accumulated cheapest price so far

    for (auto flight : flights) {
      cache[flight[0]].push_back({flight[1], flight[2]});
    }
    while (!queue.empty()) {
      int n = queue.size();
      while (n--) {
        auto q = queue.front();
        queue.pop();
        if (q.first == dst) {
          res = std::min(res, q.second);
        }
        for (auto stop : cache[q.first]) {
          if (q.second + stop.second > res) {
            continue;
          }
          queue.push({stop.first, q.second + stop.second});
        }
      }
      if (k_count++ > K) {
        break;
      }
    }
    return res == std::numeric_limits<int>::max() ? -1 : res;
  }

  // dp
  // 再来看使用Bellman Ford算法的解法，关于此算法的detail可以上网搜帖子看看。核心思想还是用的动态规划Dynamic Programming，
  // 最核心的部分就是松弛操作Relaxation，也就是DP的状态转移方程。这里我们使用一个二维DP数组，
  // 其中dp[i][j]表示最多飞i次航班到达j位置时的最少价格，那么dp[0][src]初始化为0，因为飞0次航班的价格都为0，
  // 转机K次，其实就是飞K+1次航班，我们开始遍历，i从1到K+1，每次dp[i][src]都初始化为0，因为在起点的价格也为0，
  // 然后即使遍历所有的航班x，更新dp[i][x[1]]，表示最多飞i次航班到达航班x的目的地的最低价格，用最多飞i-1次航班，
  // 到达航班x的起点的价格加上航班x的价格之和，二者中取较小值更新即可
  static int findCheapestPrice_bellman_ford(int n, std::vector<std::vector<int>> &flights, int src, int dst, int K) {
    std::vector<std::vector<int>> dp(K + 2, std::vector<int>(n, std::numeric_limits<int>::max()));
    dp[0][src] = 0;
    for (int i = 1; i <= K + 1; ++i) {
      dp[i][src] = 0;
      for (auto x : flights) {
        if (dp[i - 1][x[0]] < std::numeric_limits<int>::max()) {
          dp[i][x[1]] = std::min(dp[i][x[1]], dp[i - 1][x[0]] + x[2]);
        }
      }
    }
    return (dp[K + 1][dst] >= std::numeric_limits<int>::max()) ? -1 : dp[K + 1][dst];
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  if (Solution::findCheapestPrice(3, flights, 0, 2, 0) != 500) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findCheapestPrice(3, flights, 0, 2, 1) != 200) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findCheapestPrice_bellman_ford(3, flights, 0, 2, 0) != 500) {
    throw std::runtime_error("error 3");
  }
  if (Solution::findCheapestPrice_bellman_ford(3, flights, 0, 2, 1) != 200) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
