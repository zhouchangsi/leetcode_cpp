/**
 * https://og7kl7g6h8.feishu.cn/docx/KYasd0qGLoWjCSxeB0oc73GJneb
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int n = s.size();
    auto dp = vector<vector<int>>(n, vector<int>(2));
    dp[0][0] = s[0] == 'A' ? 0 : 1;
    dp[0][1] = s[0] == 'B' ? 1 : 0;

    for (int i = 1; i < n; i++) {
      if (s[i] == 'A') {
        // A -> A
        dp[i][0] = dp[i - 1][0];
        // B -> A
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else {
        // A -> B
        dp[i][0] = dp[i - 1][0] + 1;
        // B -> B
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
      }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main() {
  string s;
  cin >> s;

  cout << Solution().minFlipsMonoIncr(s) << '\n';
  return 0;
}
