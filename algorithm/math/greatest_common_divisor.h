#pragma once
#include <cassert>

inline int
gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

inline bool
is_even(int a)
{
  return (a & 1) == 0;
}

int
gcd_using_bit(int a, int b)
{
  if (a < b) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  bool a_is_even = is_even(a), b_is_even = is_even(b);
  if (a_is_even && b_is_even) {
    return 2 * gcd(a >> 1, b >> 1);
  } else if (a_is_even && !b_is_even) {
    return gcd(a >> 1, b);
  } else if (!a_is_even && b_is_even) {
    return gcd(a, b >> 1);
  } else {
    return gcd(b, a - b);
  }
}