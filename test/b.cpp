#include <bits/stdc++.h>
using namespace std;

void solve(int size, vector<pair<int, int>> mm) {
  int diff = INT_MAX, ans = -1;
  sort(mm.begin(), mm.end());
  for (int i = 1; i < mm.size(); i++) {
    auto [pre_start, pre_end] = mm[i - 1];
    auto [cur_start, cur_end] = mm[i];
    if (cur_start < pre_end) {
      cout << ans << endl;
      return;
    }
  }

  auto [first_start, _] = mm[0];
  if (first_start > size && first_start - size < diff) {
    diff = first_start - size;
    ans = 0;
  }

  for (int i = 1; i < mm.size(); i++) {
    auto [pre_start, pre_end] = mm[i - 1];
    auto [cur_start, cur_end] = mm[i];
    int free_size = cur_start - pre_end;
    if (free_size >= size && free_size - size < diff) {
      diff = free_size - size;
      ans = pre_end;
    }
  }
  auto [_l, last_end] = mm.back();
  int free_size = 100 - last_end;
  if (free_size >= size && free_size - size < diff) {
    diff = free_size - size;
    ans = last_end;
  }

  cout << ans << endl;
}

int main() {
  solve(1, {{0, 1}, {3, 5}, {6, 13}});
  // int size;
  // cin >> size >> ws;
  // int start, offset;
  // vector<pair<int, int>> mm;
  // while (cin >> start >> offset >> ws) {
  //   mm.push_back({start, start + offset});
  // }
  // solve(size, mm);
}