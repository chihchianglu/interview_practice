//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * LRU Cache
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache( 2 // capacity // );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#include <list>
#include <stdexcept>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) : cap_(capacity) {}

  int get(int key) {
    auto itr = m_.find(key);
    if (itr == m_.end()) {
      return -1;
    }
    l_.splice(l_.begin(), l_, itr->second); // move itr->second within l_ to l_.begin()
    return itr->second->second;
  }

  void put(int key, int value) {
    auto itr = m_.find(key);
    if (itr != m_.end()) {
      l_.erase(itr->second);
    }
    l_.push_front(std::make_pair(key, value));
    m_[key] = l_.begin();
    if (m_.size() > cap_) {
      int to_be_removed = l_.rbegin()->first;
      l_.pop_back();
      m_.erase(to_be_removed);
    }
  }
 private:
  int cap_;
  std::list<std::pair<int, int>> l_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_;
};

int main(int argc, char *argv[]) {
  LRUCache *obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  if (obj->get(1) != 1) {
    throw std::runtime_error("error 1");
  }
  obj->put(3, 3);
  if (obj->get(2) != -1) {
    throw std::runtime_error("error 2");
  }
  obj->put(4, 4);
  if (obj->get(1) != -1) {
    throw std::runtime_error("error 3");
  }
  if (obj->get(3) != 3) {
    throw std::runtime_error("error 4");
  }
  if (obj->get(4) != 4) {
    throw std::runtime_error("error 5");
  }
  return 0;
}
