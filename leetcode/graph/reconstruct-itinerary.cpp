//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
 * reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK.
 * Thus, the itinerary must begin with JFK.
 *
 * Note:
 *
 * If there are multiple valid itineraries, you should return the itinerary that has the smallest
 * lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller
 * lexical order than ["JFK", "LGB"].
 *
 * All airports are represented by three capital letters (IATA code).
 *
 * You may assume all tickets form at least one valid itinerary.
 *
 * Example 1:
 *
 * tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 *
 * Example 2:
 *
 * tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 *
 * Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 */

#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  // BFS
  static std::vector<std::string> findItinerary(std::vector<std::pair<std::string, std::string>> tickets) {
    std::vector<std::string> res;
    std::unordered_map<std::string, std::multiset<std::string>> graph;
    std::stack<std::string> st{{"JFK"}};

    for (auto &ticket : tickets) {
      graph[ticket.first].insert(ticket.second);
    }

    while (!st.empty()) {
      std::string next = st.top();
      if (graph[next].empty()) {
        res.insert(res.begin(), next);
        st.pop();
      } else {
        st.push(*graph[next].begin());
        graph[next].erase(graph[next].begin());
      }
    }
    return res;
  }

  // DFS - focus on this route
  static void dfs(std::unordered_map<std::string, std::multiset<std::string>> &graph,
                  std::string start,
                  std::vector<std::string> &res) {
    while (graph[start].size()) {
      std::string next = *graph[start].begin();
      graph[start].erase(graph[start].begin());
      dfs(graph, next, res);
    }
    res.insert(res.begin(), start);
  }
  static std::vector<std::string> findItinerary_dfs(std::vector<std::pair<std::string, std::string>> tickets) {
    std::vector<std::string> res;
    std::unordered_map<std::string, std::multiset<std::string>> graph;
    for (auto &ticket : tickets) {
      graph[ticket.first].insert(ticket.second);
    }
    dfs(graph, "JFK", res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<std::string, std::string>>
      ticket1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  std::vector<std::pair<std::string, std::string>>
      ticket2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
  std::vector<std::string> out1 = {"JFK", "MUC", "LHR", "SFO", "SJC"};
  std::vector<std::string> out2 = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};

  if (Solution::findItinerary(ticket1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findItinerary(ticket2) != out2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findItinerary_dfs(ticket1) != out1) {
    throw std::runtime_error("error 3");
  }
  if (Solution::findItinerary_dfs(ticket2) != out2) {
    throw std::runtime_error("error 4");
  }

  return 0;
}
