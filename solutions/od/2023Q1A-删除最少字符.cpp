/**
 * https://og7kl7g6h8.feishu.cn/docx/TyJVdXrDSoN91wxPr7VcMRhtnHd
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

string solve(const string& s) {
  // 统计每个字符出现的次数
  map<char, int> count_map;
  for (char ch : s) {
    count_map[ch]++;
  }

  int min_count = INT_MAX;
  for (const auto& [_, count] : count_map) {
    min_count = min(min_count, count);
  }

  string ans;
  for (char ch : s) {
    if (count_map[ch] > min_count) {
      ans += ch;
    }
  }

  return ans.empty() ? "empty" : ans;
}

int main() {
  //   cout << solve("abcdd") << endl;
  //   cout << solve("aabbccdd") << endl;
  string s;
  getline(cin, s);
  cout << solve(s) << endl;
  return 0;
}
