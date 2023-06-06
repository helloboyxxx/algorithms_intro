/**
 * @file count_inversion.cpp
 * @author Yue Chen (helloboy3x@gmail.com)
 * @brief CLRS 2-4
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <limits>
#include <vector>


void print_result(const std::vector<int>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

// It returns the number of inversions happend in this merge
template <typename T, typename A>
size_t merge_helper(std::vector<T,A>& vec , const size_t p, const size_t q, const size_t r) {
  const size_t l_size = q - p + 1;
  const size_t r_size = r - q;

  size_t inv_cnt = 0; // inversion count

  // the output vector for merged result
  std::vector<T,A> sorted;
  sorted.reserve(l_size + r_size);

  // Another solution that doesn't require the extra infinity value
  size_t i = 0; // starting index of the left sublist
  size_t j = 0; // starting index of the right sublist
  while (i < l_size && j < r_size) {
    if (vec[i + p] <= vec[j + q + 1]) {
      sorted.emplace_back(vec[i + p]);
      ++i;
    } else {
      sorted.emplace_back(vec[j + q + 1]);
      ++j;
      inv_cnt += 1+q-(i+p); // ! adding the size of the current left sublist
      // inv_cnt += l_size - i; // ! equally the same
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

  return inv_cnt;
}


template <typename T, typename A>
size_t ms_sorter(std::vector<T,A>& vec, const size_t p, const size_t r) {
  size_t inv_cnt = 0;
  if (p < r) {
    size_t q = (p + r) / 2;
    inv_cnt += ms_sorter(vec, p, q);
    inv_cnt += ms_sorter(vec, q + 1, r);
    inv_cnt += merge_helper(vec, p, q, r);
  }
  return inv_cnt;
}



int main(void) {
  std::vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  auto cnt = ms_sorter(A, 0, A.size() - 1); 
  std::cout << "inversion count: " << cnt << std::endl;
  print_result(A);
}

