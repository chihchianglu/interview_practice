//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * quick sort
 * performance:
 * Best/Avg O(nlogn)
 * Worst O(n^2)
 * space: O(1) using array
 */

#include <vector>
#include <stdexcept>

int Partition(std::vector<int> &arr, int front, int end) {
  int pivot = arr[end];
  int i = front - 1;
  for (int j = front; j < end; ++j) {
    if (arr[j] < pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  ++i;
  std::swap(arr[i], arr[end]);
  return i;
}

void QuickSort(std::vector<int> &arr, int front, int end) {
  if (front < end) {
    int pivot = Partition(arr, front, end);
    QuickSort(arr, front, pivot - 1);
    QuickSort(arr, pivot + 1, end);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {9, 4, 1, 6, 7, 3, 8, 2, 5};
  std::vector<int> out = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  QuickSort(vec, 0, vec.size() - 1);
  if (vec != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
