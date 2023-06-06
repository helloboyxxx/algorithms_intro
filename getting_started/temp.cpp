#include <iostream>


int main(void) {
  int x = 3;
  int y = 5;
  int * const a = &x;  // we can change the value here
  // const int * a; // These 
  // int const * a; // two are the same
  std::cout << *a << std::endl;
  *a = y;
  std::cout << *a << std::endl;
}
