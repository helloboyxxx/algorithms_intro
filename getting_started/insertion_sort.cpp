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

void print_result(const int A[], const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

// void my_sorter(int A[], const int size, std::function<int(int, int)> func_ptr) {
void my_sorter(int A[], const int size, bool (*func_ptr)(int, int)) {
  for (int j = 1; j < size; ++j) {
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
  int A[6] = {5, 2, 4, 6, 1, 3};
  int B[6] = {5, 2, 4, 6, 1, 3};

  int size = sizeof(A)/sizeof(A[0]);
  print_result(A, size);

  // non-decreasing insertion sort
  
  // my_sorter(A, size, std::less<int>());
  my_sorter(A, size, [](int a, int b) { return a < b; });

  // non-increading insertion sort
  // my_sorter(B, size, std::greater<int>());
  my_sorter(B, size, [](int a, int b) { return a > b; });

  print_result(A, size);
  print_result(B, size);

  return 0;
}
