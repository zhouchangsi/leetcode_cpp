#include <bits/stdc++.h>
using namespace std;

void solve(int limit, vector<int> tasks) {
  int n = tasks.size();
  int rest = 0;
  for (auto task : tasks) {
    rest += task;
    rest -= limit;
    if (rest < 0) rest = 0;
  }
  cout << n + rest / limit + (rest % limit != 0) << '\n';
}

int main() {
  solve(1, {1, 2, 3, 4});
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   int limit, n;
  //   cin >> limit >> n;
  //   vector<int> tasks(n);
  //   for (int i = 0; i < n; i++) {
  //     cin >> tasks[i];
  //   }
  //   solve(limit, tasks);
  return 0;
}