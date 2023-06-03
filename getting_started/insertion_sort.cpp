/**
 * @file insertion_sort.cpp
 * @author Yue Chen (helloboy3x@gmail.com)
 * @brief practice for 2.1 and 2.1-2
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <functional>
#include <vector>

#include "sorters.hpp"



// void my_sorter(int A[], std::function<int(int, int)> func_ptr) {
void ins_sorter(std::vector<int>& A, int(*func_ptr)(int, int)) {
  for (auto j = 1; j < A.size(); ++j) {
    int key = A[j];
    
    int i = j - 1;
    while ( i >= 0 && func_ptr(key, A[i]) ) {
      A[i + 1] = A[i];
      --i;
    }
    A[i + 1] = key;
  }
}

int main() {
  //int A[6] = {5, 2, 4, 6, 1, 3};
  // int B[6] = {5, 2, 4, 6, 1, 3};

  std::vector<int> A = {5, 2, 4, 6, 1, 3};
  std::vector<int> B = A; 

  print_result(A);

  // non-decreasing insertion sort
  
  // my_sorter(A, size, std::less<int>());
  ins_sorter(A, +[](int a, int b) { return static_cast<int>(a < b); });

  // non-increading insertion sort
  // my_sorter(B, size, std::greater<int>());
  ins_sorter(B, +[](int a, int b) { return static_cast<int>(a > b); });

  print_result(A);
  print_result(B);

  return 0;
}
