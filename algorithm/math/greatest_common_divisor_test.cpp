#include "./greatest_common_divisor.h"

#include <cassert>
#include <iostream>

int
main()
{
  int a = 12, b = 18;
  assert(gcd(a, b) == 6);
  assert(gcd_using_bit(a, b) == 6);
  std::cout << "----------- 啊老师的课发动机 asldkfj" << std::endl;
  return 0;
}