/**
 * https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int balancedString(string s)
  {
    int n = s.length();
    int k = n / 4;
    vector<int> count(128, 0);
    for (char c : s)
    {
      count[c]++;
    }

    int l = 0, r = 0, ans = n;
    while (r < n)
    {
      count[s[r]]--;

      while (l < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k)
      {
        ans = min(ans, r - l + 1);
        count[s[l++]]++;
      }

      r++;
    }
    return ans;
  }
};