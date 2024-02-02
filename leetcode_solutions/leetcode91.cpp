#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    if (n == 0)
      return 0;
  

    vector<int> dp(n, 0);
    dp[0] = s[0] == '0' ? 0 : 1;

    for (int i = 1; i < n; ++i) {

      if (s[i] == '0') {
        if (s[i - 1] == '0'   //...00
            || s[i - 1] > '2' //...30
        )
          return 0;
        else
          dp[i] = i == 1 ? 1 // 10, 20
                         : dp[i - 2];

      } else {
        if (s[i - 1] == '0'                    // .+0[1-9]$
            || s[i - 1] > '2'                  // .+[3-9][1-9]$
            || (s[i - 1] == '2' && s[i] > '6') // .+2[7-9]$
        )
          dp[i] = dp[i - 1];
        else
          dp[i] = i == 1 ? dp[i - 1] + 1 // 1x, 2x
                         : dp[i - 1] + dp[i - 2];
      }
    }

    return dp[n - 1];
  }
};

TEST(leetcode91, solution)
{
  Solution s;
  string str;

  str = "12";
  ASSERT_EQ(s.numDecodings(str), 2);

  str = "226";
  ASSERT_EQ(s.numDecodings(str), 3);

  str = "0";
  ASSERT_EQ(s.numDecodings(str), 0);

  str = "06";
  ASSERT_EQ(s.numDecodings(str), 0);

  str = "10";
  ASSERT_EQ(s.numDecodings(str), 1);

  str = "27";
  ASSERT_EQ(s.numDecodings(str), 1);

  str = "101";
  ASSERT_EQ(s.numDecodings(str), 1);

  str = "100";
  ASSERT_EQ(s.numDecodings(str), 0);

  str = "110";
  ASSERT_EQ(s.numDecodings(str), 1);

  str = "230";
  ASSERT_EQ(s.numDecodings(str), 0);

  str = "12120";
  ASSERT_EQ(s.numDecodings(str), 3);

  str = "12120";
  ASSERT_EQ(s.numDecodings(str), 3);

  str = "12120";
  ASSERT_EQ(s.numDecodings(str), 3);
}