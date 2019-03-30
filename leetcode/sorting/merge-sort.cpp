//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * merge sort
 * performance:
 * Best/Avg/Worst O(nlogn)
 * space O(n), O(1) for linked list
 */

#include <vector>
#include <numeric>
#include <stdexcept>

void Merge(std::vector<int> &arr, int front, int mid, int end) {
  std::vector<int> left_sub(arr.begin() + front, arr.begin() + mid + 1),
      right_sub(arr.begin() + mid + 1, arr.begin() + end + 1);

  left_sub.insert(left_sub.end(), std::numeric_limits<int>::max());
  right_sub.insert(right_sub.end(), std::numeric_limits<int>::max());
  int idx_left = 0, idx_right = 0;

  for (int i = front; i <= end; ++i) {
    if (left_sub[idx_left] <= right_sub[idx_right]) {
      arr[i] = left_sub[idx_left++];
    } else {
      arr[i] = right_sub[idx_right++];
    }
  }
}

void MergeSort(std::vector<int> &arr, int front, int end) {
  if (front < end) {
    int mid = (front + end) / 2;
    MergeSort(arr, front, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, front, mid, end);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {5, 3, 8, 6, 2, 7, 1, 4};
  std::vector<int> out = {1, 2, 3, 4, 5, 6, 7, 8};
  MergeSort(vec, 0, vec.size() - 1);
  if (vec != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
