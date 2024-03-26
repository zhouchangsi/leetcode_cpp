#include <bits/stdc++.h>
using namespace std;

struct Interval {
  int start;
  int end;
  bool operator<(const Interval &b) const { return start < b.start; }
  bool is_overlap(const Interval &b) {
    return !(start < b.start && end < b.start) &&
           !(start > b.end && end > b.end);
  }
};

int solution() {
  int size = 1;
  cin >> size;
  vector<Interval> mem;
  // vector<pair<int, int>> mem = {{0, 1}, {3, 5}, {6, 13}};
  int offset, value;
  while (cin >> offset >> value) {
    mem.emplace_back(offset, offset + value);
  }

  sort(mem.begin(), mem.end());

  // cout << size << endl;
  // for (auto i : mem) {
  //   cout << i.first << "," << i.second << " ";
  // }

  int n = mem.size();
  for (int i = 0; i < n - 1; i++) {
    if (mem[i].is_overlap(mem[i + 1])) {
      return -1;
    }
  }

  int diff = 100;
  int ans = -1;
  if (mem[0].start - size > 0) {
    diff = mem[0].start;
    ans = 0;
  }
  for (int i = 0; i < n; i++) {
    int pre_end = mem[i].end;
    if (pre_end >= 100) break;
    int cur_start = i != n - 1 ? mem[i + 1].start : 100;
    int free_size = cur_start - pre_end;
    if (free_size >= size && free_size - size < diff) {
      diff = free_size - size;
      ans = pre_end;
    }
  }

  return ans;
}
int main() {
  cout << solution() << endl;
  return 0;
}
