#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>


inline void print_result(const std::vector<int>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

// merge sort sorter
void ms_sorter(std::vector<int>& A, const size_t p, const size_t r);

// insertion sort
void ins_sorter(int A[], const int size, int(*func_ptr)(int, int));