#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int countPrimes(int n)
  {
    if (n <= 2)
      return 0;

    vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;

    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (!is_prime[i]) {
        continue;
      }
      ++count;

      // 如果 xxx 是质数，那么大于x的x的倍数 2x,3x...一定不是质数
      // 从2x开始标记其实是冗余的，应该直接从x⋅x
      // 开始标记，因为 2x,3x,…2x,3x,\ldots2x,3x,… 这些数一定在 xxx
      // 之前就被其他数的倍数标记过了，例如 222 的所有倍数，333 的所有倍数等。
      if (i > n / i) {
        continue;
      }

      for (int j = i * i; j < n; j += i) {
        is_prime[j] = false;
      }
    }

    return count;
  }
};

TEST(leetcode204, solution) {}