/**
 * https://og7kl7g6h8.feishu.cn/docx/OAMMdvCuDocxiZxW5vvcJztgnAe
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

void slide_window(string line) {
  unordered_map<char, int> cnt;
  for (char ch : line) {
    cnt[ch]++;
  }

  int num = line.length() / 4;
  unordered_map<char, int> cnt_sub;
  for (const auto &[ch, count] : cnt) {
    if (count > num) {
      cnt_sub[ch] = count - num;
    }
  }

  if (cnt_sub.empty()) {
    cout << 0 << endl;
    return;
  }

  auto check = [&cnt_sub](const unordered_map<char, int> &cnt_win) {
    for (const auto [ch, count] : cnt_sub) {
      if (cnt_win.find(ch) == cnt_win.end() || cnt_win.at(ch) < count) {
        return false;
      }
    }
    return true;
  };

  unordered_map<char, int> cnt_win;
  int ans = INT_MAX;
  int l = 0;
  for (int r = 0; r < line.length(); r++) {
    cnt_win[line[r]]++;
    while (check(cnt_win)) {
      ans = min(ans, r - l + 1);
      cnt_win[line[l]]--;
      l++;
    }
  }

  cout << ans << endl;
}

int main() {
  //   slide_window("AASW");

  string s;
  getline(cin, s);
  slide_window(s);
  return 0;
}
