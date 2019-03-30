//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * insertion sort
 * performance:
 * Best O(n) comparison, O(1) swaps
 * Avg/Worst O(n^2) comparison, swaps
 * space O(1)
 */

#include <vector>
#include <stdexcept>

void InsertionSort(std::vector<int> &vec) {
  int n = vec.size(), j = 0;
  for (int i = 1; i < n; ++i) {
    int key = vec[i]; // key mean the value we want to deal with now
    for (j = i - 1; j >= 0 && vec[j] > key; --j) { // 從後往前找看要insert到哪
      vec[j + 1] = vec[j]; // 往右挪
    }
    vec[j + 1] = key; // 講key insert到正確位置
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {5, 3, 1, 2, 6, 4};
  std::vector<int> out = {1, 2, 3, 4, 5, 6};
  InsertionSort(vec);
  if (vec != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
