/**
 * @file insertion_sort.cpp
 * @author Yue Chen (helloboy3x@gmail.com)
 * @brief implementation for 2.3
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <limits>


void print_result(const int A[], const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}



void merge_helper(int A[], int p, int q, int r) {
  int tot_leng = r - p + 1;
  int l_size = q - p + 1;
  int r_size = r - q;

  // create two temporary array and copy A's subarray into them
  int L[l_size + 1];
  int R[r_size + 1];

  for (int i = 0; i < l_size; ++i) {
    L[i] = A[i + p];
  }
  for (int i = 0; i < r_size; ++i) {
    R[i] = A[i + q + 1];
  }
  L[l_size] = std::numeric_limits<int>::max();
  R[r_size] = std::numeric_limits<int>::max();

  // smallest index of the two subarrays
  int i = 0; 
  int j = 0;
  for (int k = p; k <= r; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    }
    else {
      A[k] = R[j];
      ++j;
    }
  }

  // Another solution that doesn't require the extra infinity value
  /*
  int k = p; 
  while (i < l_size && j < r_size) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    } else {
      A[k] = R[j];
      ++j;
    }
    ++k;
  }
  while (i < l_size) {
    A[k] = L[i];
    ++i;
    ++k;
  }
  while (j < r_size) {
    A[k] = R[j];
    ++j;
    ++k;
  }
  */
}

void my_sorter(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    my_sorter(A, p, q);
    my_sorter(A, q + 1, r);
    merge_helper(A, p, q, r);
  }

}

int main() {
  // int A[size] = {5, 2, 4, 6, 1, 3};
  int A[] = {2, 4, 5, 1, 3, 6, 123, 5, 5, 234, 4, 57, 79, 23578 ,7 ,345, 4235, 567};
  const int size = sizeof(A) / sizeof(A[0]);
  my_sorter(A, 0, size - 1);
  print_result(A, size);
}