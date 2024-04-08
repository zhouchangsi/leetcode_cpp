/**
 * https://og7kl7g6h8.feishu.cn/docx/HoCIdue43o7EjAxSTvFcmTu5nRh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  getline(cin, line);
  istringstream iss(line);
  vector<int> colors;
  int color;

  while (iss >> color) {
    colors.push_back(color);
  }
  int n;
  cin >> n;

  int count[3] = {0, 0, 0};
  int ans = 0;
  int cur = 0;

  if (n > colors.size()) {
    n = colors.size();
  }

  for (int i = 0; i < n; i++) {
    int num = colors[i];
    count[num]++;
  }
  cur = *max_element(count, count + 3, less<int>());
  ans = max(ans, cur);

  for (int right = n; right < colors.size(); right++) {
    int num = colors[right];
    count[num]++;
    int left = colors[right - n];
    count[left]--;
    ans = max(ans, count[num]);
  }

  cout << ans << endl;

  return 0;
}
