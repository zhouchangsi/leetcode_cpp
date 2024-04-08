/**
 * https://og7kl7g6h8.feishu.cn/docx/AE2tdlW1moStOKxPMtock2ADnhc
 */
#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> prices, int budget) {
  sort(prices.begin(), prices.end());
  int max_cost = -1;
  for (int l = 0; l < prices.size() - 2; l++) {
    if (l > 0 && prices[l] == prices[l - 1]) continue;
    int r = prices.size() - 1, m = l + 1;
    int sum_limit = budget - prices[l];
    while (m < r) {
      int sum = prices[l] + prices[m] + prices[r];
      if (sum <= budget) {
        max_cost = max(max_cost, sum);
        m++;
      } else {
        r--;
      }
    }
  }

  cout << max_cost;
}

int main() {
  vector<int> prices;
  string line;
  getline(cin, line);
  istringstream iss(line);
  while (getline(iss, line, ',')) prices.push_back(stoi(line));

  int budget;
  cin >> budget;

  solution(prices, budget);
}