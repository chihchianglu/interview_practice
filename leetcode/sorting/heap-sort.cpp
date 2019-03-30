//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * heap sort
 * performance:
 * Best/Avg/Worst O(nlogn)
 * space O(1)
 */

#include <vector>
#include <stdexcept>

// any index i
// left child = index i * 2
// right child = index i * 2 + 1
void MaxHeapify(std::vector<int> &array, int root, int length) {
  int left = 2 * root, right = 2 * root + 1, largest = root;

  if (left <= length && array[left] > array[largest]) {
    largest = left;
  }

  if (right <= length && array[right] > array[largest]) {
    largest = right;
  }

  if (largest != root) {
    std::swap(array[root], array[largest]);
    MaxHeapify(array, largest, length); // update sub-trees
  }
}

void BuildMaxHeap(std::vector<int> &array) {
  int n = array.size();
  for (int i = n / 2; i > 0; --i) {
    MaxHeapify(array, i, n - 1); // minus 1 due to it's index
  }
}

void HeapSort(std::vector<int> &array) {
  // 要滿足Binary Heap特有的「parent-child」之關係，只要讓矩陣中index(0)的位置閒置，從index(1)開始存放資料，
  // 即可使用矩陣(array)來表示Binary Heap。
  array.insert(array.begin(), 0); // index 0 is not used
  BuildMaxHeap(array);

  int size = array.size() - 1;
  for (int i = array.size() - 1; i > 1; --i) {
    std::swap(array[1], array[i]);
    --size;
    MaxHeapify(array, 1, size);
  }

  array.erase(array.begin()); // remove index 0
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {9, 4, 1, 6, 7, 3, 8, 2, 5};
  std::vector<int> out = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  HeapSort(vec);
  if (vec != out) {
    throw std::runtime_error("error");
  }

  return 0;
}
