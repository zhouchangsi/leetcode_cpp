/**
 * https://og7kl7g6h8.feishu.cn/docx/DfZdd5d1nor9CExg7sVck1zenae
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void slide_window(string a, string s) {
  const char d = a[0];
  int l = 0;
  int ans = 0;
  int count[128] = {0};
  for (int r = 0; r < s.length(); r++) {
    if (s[r] == d) {
      l = r + 1;
      fill(count, count + 128, 0);
      continue;
    }
    count[s[r]]++;
    while (count[s[r]] == 3) {
      count[s[l]]--;
      l++;
    }
    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
}

int main() {
  string a, s;
  cin >> a >> s;
  slide_window(a, s);

  return 0;
}
