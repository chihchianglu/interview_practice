//
// Created by Lu, Chih-chiang on 2019-01-24.
//


/**
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_map>

// Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
 public:
  // DFS
  UndirectedGraphNode *cloneGraph_dfs(UndirectedGraphNode *node) {
    std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> cache;
    return clone(node, cache);
  }
  UndirectedGraphNode *clone(UndirectedGraphNode *node,
                             std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &cache) {
    if (!node) {
      return node;
    }

    if (cache.find(node) != cache.end()) {
      return cache[node];
    }

    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    cache[node] = new_node;
    for (auto neighbor : node->neighbors) {
      new_node->neighbors.push_back(clone(neighbor, cache));
    }
    return new_node;
  }

  // BFS - go with this route
  UndirectedGraphNode *cloneGraph_bfs(UndirectedGraphNode *node) {
    std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> cache; // original node -> copy node
    std::queue<UndirectedGraphNode *> queue;
    if (!node) {
      return node;
    }

    UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
    cache[node] = head;
    queue.push(node);
    while (!queue.empty()) {
      auto cur = queue.front();
      queue.pop();
      for (auto neighbor : cur->neighbors) {
        if (cache.find(neighbor) == cache.end()) {
          queue.push(neighbor);
          cache[neighbor] = new UndirectedGraphNode(neighbor->label);
        }
        cache[cur]->neighbors.push_back(cache[neighbor]);
      }
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
