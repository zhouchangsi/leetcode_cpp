#include "common_headers.h"
class Solution
{
public:
  string toHex(int num)
  {
    const char* hex = "0123456789abcdef";
    string result;
    for (int i = 0; i < 8; ++i) {
      result.push_back(hex[num & 0xf]); // why 0xf? 0xf = 15 = 1111
      num >>= 4;
    }
    // why reverse? because we push_back from low to high
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result[0] == '0') {
      result.erase(result.begin());
    }
    return result;
  }
};