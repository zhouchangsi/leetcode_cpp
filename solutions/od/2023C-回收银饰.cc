#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums) {
  priority_queue<int> pq(nums.begin(), nums.end());
  while (pq.size() > 2) {
    int z = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    int x = pq.top();
    pq.pop();

    int t = 0;
    if (z == y && y == x) {
      continue;
    } else if (x == y && y < z) {
      t = z - y;
    } else if (x < y && y == z) {
      t = y - x;
    } else {
      t = abs((z - y) - (y - x));
    }

    if (t == 0) continue;

    pq.emplace(t);
  }
  if (pq.size() > 0) {
    cout << pq.top() << endl;
  } else {
    cout << 0 << endl;
  }
}

int main() {
  //   solve({3, 7, 10});
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  solve(nums);
  return 0;
}