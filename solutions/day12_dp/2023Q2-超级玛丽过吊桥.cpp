/**
 * https://og7kl7g6h8.feishu.cn/docx/CbcodlVJZoI4aqx8W9BcTVpmn9g
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>


using namespace std;

int calc_ways(int M, int N, int K, const unordered_set<int> &traps) {
  auto dp = vector<vector<int>>(N + 2, vector<int>(M + 1, 0));
  dp[0][M] = 1;  // 开始时rest_life = M ,
                 // dp[0][rest_life]表示以rest_life为生命值的方式走到的方法数
  for (int i = 1; i <= N + 1; i++) {
    for (int j = max(0, i - 3); j < i; j++) {
      for (int k = 0; k <= M; k++) {
        if (!traps.count(i)) {
          dp[i][k] += dp[j][k];
        } else if (k - 1 > 0)  // 陷阱，生命值减一
        {
          dp[i][k - 1] += dp[j][k];
        }
      }
    }
  }

  return accumulate(dp[N + 1].begin(), dp[N + 1].end(), 0);
}

int main() {
  int M, N, K;
  cin >> M >> N >> K;
  unordered_set<int> traps;
  for (int i = 0; i < K; i++) {
    int trap;
    cin >> trap;
    traps.insert(trap);
  }

  cout << calc_ways(M, N, K, traps) << endl;

  return 0;
}
