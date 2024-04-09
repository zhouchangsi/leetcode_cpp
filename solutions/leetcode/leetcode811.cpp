#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<string, int> dic;

 public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    for (auto &s : cpdomains) {
      size_t pos{};
      int c = stoi(s, &pos);
      int n = s.size();
      for (size_t i = pos; i < n; ++i) {
        if (s[i] == '.' || s[i] == ' ') {
          dic[s.substr(i + 1)] += c;
        }
      }
    }
    vector<string> ans;
    for (auto &[s, c] : dic) {
      ans.emplace_back(to_string(c) + " " + s);
    }
    return ans;
  }
};