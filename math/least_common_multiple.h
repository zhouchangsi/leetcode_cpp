#pragma once
#include "./greatest_common_divisor.h"

int
lcm(int a, int b)
{
  return a * b / gcd(a, b);
}