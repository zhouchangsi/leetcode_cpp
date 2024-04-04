/**
 * https://og7kl7g6h8.feishu.cn/docx/CsCzdCpeCoh7WmxMD8Acfk90nHd
 */
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string longest_public_string(string a, string b) {
  int n = a.size(), m = b.size();
  auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  int max_len = 0, end = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > max_len) {
          max_len = dp[i][j];
          end = i - 1;
        }
      }
    }
  }
  return a.substr(end - max_len + 1, max_len);
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << longest_public_string(s1, s2) << endl;
  return 0;
}