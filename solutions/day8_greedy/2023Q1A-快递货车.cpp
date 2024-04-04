// https://og7kl7g6h8.feishu.cn/docx/AIvEd5MWRoSw5QxwQPycGXLunvf
#include <bits/stdc++.h>
using namespace std;

void solution(std::vector<int> &weights, int weight_limit) {
  sort(weights.begin(), weights.end());
  int cur_weight = 0;
  int ans = 0;
  for (int w : weights) {
    cur_weight += w;
    if (cur_weight > weight_limit) {
      break;
    }
    ans++;
  }

  cout << ans << endl;
}

int main() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> weights;
  while (getline(ss, line, ',')) weights.push_back(stoi(line));

  int weight_limit;
  cin >> weight_limit;

  solution(weights, weight_limit);

  return 0;
}
