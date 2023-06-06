#include <iostream>

#include "merge_sort.cpp"
#include "sorters.hpp"

bool find_sum(std::vector<int> &vec, const int S) {
  size_t l = 0;
  size_t r = vec.size() - 1;
  ms_sorter(vec, 0, r);   // merge sort. It does change vec here.
  while (l <= r) {
    auto cur_sum = vec[l] + vec[r];
    if (cur_sum == S)
      return true;
    if (cur_sum < S)
      ++l;
    else
      --r;
  }
  return false;
}

int main(void) {
  // std::vector<int> A = {2, 4, 1, 3, 6, 123, 5, 234, 4, 57, 79, 23578 ,7 ,345, 4235, 567};
  std::vector<int> A = {4, 2, 5, -8, 3, 6};
  // std::vector<int> A = {1};
  bool result_1 = find_sum(A, 2);
  bool result_2 = find_sum(A, 16);
  std::cout << result_1 << std::endl;
  std::cout << result_2 << std::endl;
}
