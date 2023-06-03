/**
 * @file binary_search_first.cpp
 * @author Yue Chen (helloboy3x@gmail.com)
 * @brief My implementation of my own binary search pseudocode for 2.3-5
 * @version 0.1
 * @date 2023-05-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

/**
 * @brief Returns the index of the target in the sorted vector A.
 * It returns -1 when the target is not found or the vector.size() == 0
 * @tparam T 
 * @param A 
 * @param target 
 * @return ssize_t 
 */
template<typename T>
ssize_t my_bs(const std::vector<T>& A, T target) {
  if (A.size() == 0) {
    return -1;
  }
  ssize_t left = 0;
  ssize_t right = A.size();
  
  while (true) {
    ssize_t i = (left + right) / 2;
    if (A[i] == target) {
      return i;
    }
    if (left == right) {
      // not equal and we end searching
      return -1;
    } else if (A[i] < target) {
      left = i + 1;
    } else {
      right = i - 1;
    }
  }
}


int main() {
  std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ssize_t i = my_bs(A, 8);

  std::cout << i << std::endl;

}