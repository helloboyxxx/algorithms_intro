/**
 * @file insertion_sort.cpp
 * @author Yue Chen (helloboy3x@gmail.com)
 * @brief implementation for 2.3. Also having solution for 2.3-2 
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <limits>
#include <vector>

#include "sorters.hpp"


template <typename T, typename A>
void merge_helper(std::vector<T,A>& vec , const size_t p, const size_t q, const size_t r) {
  const size_t l_size = q - p + 1;
  const size_t r_size = r - q;

  // the output vector for merged result
  std::vector<T,A> sorted;
  sorted.reserve(l_size + r_size);

  // Another solution that doesn't require the extra infinity value
  size_t i = 0;
  size_t j = 0;
  while (i < l_size && j < r_size) {
    if (vec[i + p] <= vec[j + q + 1]) {
      sorted.emplace_back(vec[i + p]);
      ++i;
    } else {
      sorted.emplace_back(vec[j + q + 1]);
      ++j;
    }
  }
  while (i < l_size) {
    sorted.emplace_back(vec[i + p]);
    ++i;
  }
  while (j < r_size) {
    sorted.emplace_back(vec[j + q + 1]);
    ++j;
  }

  // replace the original subarray with the sorted one
  for (auto x = p; x < r + 1; x++) {
    vec[x] = sorted[x - p];
  }
}

template <typename T, typename A>
void ms_sorter(std::vector<T,A>& vec, const size_t p, const size_t r) {
  if (p < r) {
    size_t q = (p + r) / 2;
    ms_sorter(vec, p, q);
    ms_sorter(vec, q + 1, r);
    merge_helper(vec, p, q, r);
  }
}

// int main() {
//   // std::vector<int> A = {4, 2, 5, 1, 3, 6};
//   std::vector<int> A = {2, 4, 1, 3, 6, 123, 5, 234, 4, 57, 79, 23578 ,7 ,345, 4235, 567};
//   ms_sorter(A, 0, A.size() - 1);
//   print_result(A);
// }
