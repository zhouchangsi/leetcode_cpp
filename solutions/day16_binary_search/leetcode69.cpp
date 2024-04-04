/**
 * https://leetcode.cn/problems/sqrtx/description/
 * https://r07na4yqwor.feishu.cn/docx/InkhdDOWzodPZnxXgiMcKLIXnUe
 */
#include "../leetcode/leetcode.h"
#include <math.h>

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x == 0)
    {
      return 0;
    }

    double C = x, x0 = x;
    while (true)
    {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 - xi) < 1e-7)
      {
        break;
      }
      x0 = xi;
    }
    return int(x0);
  }
};

class Solution
{
public:
  int mySqrt(int x)
  {
    // 需要寻找出一个数 ans ，使得 ans * ans <= x ，并且 ans 总是尽可能更大
    // 于是，开始在 [ 0  , x ] 这个区间中去查找
    // 在查找过程中，不断的去缩小区间

    // 左区间开始位置为 0
    int left = 0;

    // 右区间开始位置为 x
    int right = x;

    // 算法平方根的结果，一开始为一个不可能的数 -1
    int ans = -1;

    // 开始在区间中查找
    while (left <= right)
    {

      // 先定位中间元素
      int mid = left + (right - left) / 2;

      // 由于 x 的范围能到达 int 的最大值
      // 所以 mid 也有可能很大，导致 mid * mid 超过 int 的范围
      // 因此使用 long
      // 判断 mid 是否符合要求
      // 1、如果发现不够
      if ((long)mid * mid <= x)
      {

        // 保留结果
        ans = mid;

        // 同时，可以舍去 left 左边的所有元素
        left = mid + 1;

        // 2、如果发现超过
      }
      else
      {

        // 同时，可以舍去 right 右边的所有元素
        right = mid - 1;
      }
    }

    // 返回结果
    return ans;
  }
};