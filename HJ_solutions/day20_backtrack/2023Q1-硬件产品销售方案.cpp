/**
 * https://og7kl7g6h8.feishu.cn/docx/PCJ5dveJkoax2yx2vsMcxUNPnUc
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  string line = "100, 200, 300, 500";
  int amount = 500;
  getline(cin, line);
  amount = stoi(line);
  getline(cin, line);
  stringstream ss(line);
  vector<int> prices;
  string price;
  while (getline(ss, price, ',')) {
    prices.push_back(stoi(price));
  }

  const int n = prices.size();
  vector<vector<int>> res;
  vector<int> path;
  int sum = 0;
  function<void(int)> backtrack = [&](int start) {
    if (sum > amount) return;
    if (sum == amount) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < n; i++) {
      path.push_back(prices[i]);
      sum += prices[i];
      backtrack(i);
      path.pop_back();
      sum -= prices[i];
    }
  };
  backtrack(0);
  const int res_size = res.size();
  cout << "[";
  for (int i = 0; i < res_size; i++) {
    cout << "[";
    const vector<int>& _prices = res[i];
    const int _prices_size = _prices.size();
    for (int j = 0; j < _prices_size; j++) {
      cout << _prices[j] << (j == _prices_size - 1 ? "" : ", ");
    }
    cout << (i == res_size - 1 ? "]" : "], ");
  }
  cout << "]";
}