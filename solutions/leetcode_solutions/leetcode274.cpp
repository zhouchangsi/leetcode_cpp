#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < citations.size(); i++) {
      int h = min(i + 1, citations[i]);
      ans = max(ans, h);
    }
    return ans;
  }
};