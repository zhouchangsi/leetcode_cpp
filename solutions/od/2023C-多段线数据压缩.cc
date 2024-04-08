#include <bits/stdc++.h>
using namespace std;

void solve(string line) {
  vector<pair<int, int>> points;
  stringstream ss(line);
  int x, y;
  while (ss >> x >> y) {
    points.emplace_back(x, y);
  }
  int n = points.size();
  vector<pair<int, int>> res;
  for (int i = 1; i < n - 1; i++) {
    auto [xa, ya] = points[i - 1];
    auto [xb, yb] = points[i];
    auto [xc, yc] = points[i + 1];
    if ((xc - xb != xb - xa) || (yc - yb != yb - ya)) {
      res.emplace_back(xb, yb);
    }
  }
  auto [x1, y1] = points[0];
  auto [xn, yn] = points[n - 1];
  cout << x1 << ' ' << y1 << ' ';
  for (auto [x, y] : res) {
    cout << x << ' ' << y << ' ';
  }
  cout << xn << ' ' << yn << '\n';
}

int main() {
  // solve("2 8 3 7 3 6 3 5 4 4 5 3 6 2 7 3 8 4 7 5");
  string line;
  getline(cin, line);
  solve(line);
}