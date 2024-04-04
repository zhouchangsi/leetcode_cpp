/**
 * https://og7kl7g6h8.feishu.cn/docx/EIEjdKhddoy5ePxqG1TcGnytneh
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Station {
  int distance;
  int cost;
};

void dp(int distance, int n, vector<Station> s) {
  auto min_time = vector<int>(n + 2, INT_MAX);
  min_time[0] = 0;

  for (int i = 1; i <= n + 1; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (s[i].distance - s[j].distance > 1000) {
        break;
      }

      min_time[i] = min(min_time[i], min_time[j] + s[i].cost);
    }
  }

  cout << min_time.back() + distance / 100 << '\n';
}

int main() {
  //   dp(1500, 4, {{0, 0}, {300, 3}, {600, 2}, {1000, 1}, {1200, 2}, {1500,
  //   0}});

  int distance, n;
  cin >> distance >> n;
  auto s = vector<Station>(n + 2);
  s[0] = {0, 0};
  for (int i = 1; i <= n; i++) {
    cin >> s[i].distance >> s[i].cost;
    s[i].cost++;
  }
  s[n + 1] = {distance, 0};
  dp(distance, n, s);
}