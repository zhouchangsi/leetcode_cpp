/**
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
  {
    unordered_map<int, int> map;
    for (const int& n1 : nums1) {
      map[n1] = map.count(n1) == 0 ? 1 : map[n1] + 1;
    }
    vector<int> result;
    for (const int& n2 : nums2) {
      if (map.count(n2) > 0 && map[n2] > 0) {
        result.push_back(n2);
        map[n2]--;
      }
    }
    return result;
  }
};