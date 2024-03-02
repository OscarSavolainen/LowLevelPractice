#include <iostream>

int foo(int n) {
  if (n == 1) {
    return 1;
  }
  return n + foo(n-1);
}

int main() {
  std::cout << foo(5) << std::endl;

}
