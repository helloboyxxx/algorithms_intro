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


void print_result(const std::vector<int>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}



void merge_helper(std::vector<int>& A, const size_t p, const size_t q, const size_t r) {
  const size_t l_size = q - p + 1;
  const size_t r_size = r - q;

  // the output vector for merged result
  std::vector<int> sorted;
  sorted.reserve(l_size + r_size);

  // Another solution that doesn't require the extra infinity value
  size_t i = 0;
  size_t j = 0;
  while (i < l_size && j < r_size) {
    if (A[i + p] <= A[j + q + 1]) {
      sorted.emplace_back(A[i + p]);
      ++i;
    } else {
      sorted.emplace_back(A[j + q + 1]);
      ++j;
    }
  }
  while (i < l_size) {
    sorted.emplace_back(A[i + p]);
    ++i;
  }
  while (j < r_size) {
    sorted.emplace_back(A[j + q + 1]);
    ++j;
  }

  // replace the original subarray with the sorted one
  for (size_t x = p; x < r + 1; x++) {
    A[x] = sorted[x - p];
  }
}

void my_sorter(std::vector<int>& A, const size_t p, const size_t r) {
  if (p < r) {
    int q = (p + r) / 2;
    my_sorter(A, p, q);
    my_sorter(A, q + 1, r);
    merge_helper(A, p, q, r);
  }

}

int main() {
  // std::vector<int> A = {4, 2, 5, 1, 3, 6};
  std::vector<int> A = {2, 4, 5, 1, 3, 6, 123, 5, 5, 234, 4, 57, 79, 23578 ,7 ,345, 4235, 567};
  my_sorter(A, 0, A.size() - 1);
  print_result(A);
}
