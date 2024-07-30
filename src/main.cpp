#include <iostream>

#include "./containers/darray.hpp"

using namespace roo;

int main(void) {
  auto arr = darray<i32>();

  for (i32 i = 0; i < 400; i++) {
    arr.push(i);
    printf("%d\n", arr[i]);
  }

  return !std::cout;
}
