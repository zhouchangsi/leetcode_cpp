// https://og7kl7g6h8.feishu.cn/docx/WyahdwqCLoz0TNxY0Fmc8PUVnSg
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;

  Interval(int s, int e) : start(s), end(e) {}
};

void greedy(vector<Interval>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const Interval& a, const Interval& b) { return a.start < b.start; });
  int ans = 0;
  int pre_end = -1e9;
  for (const auto& interval : intervals) {
    int start = interval.start;
    int end = interval.end;
    if (start >= pre_end) {
      ans++;
      pre_end = end;
    } else if (start < pre_end && pre_end <= end) {
      continue;
    } else if (pre_end > end) {
      pre_end = end;
    }
  }
  cout << ans << endl;
}

int main() {
  int N;
  cin >> N;

  vector<Interval> intervals;
  for (int i = 0; i < N; ++i) {
    int start, during;
    cin >> start >> during;
    int end = start + during + 15;
    intervals.push_back({start, end});
  }

  greedy(intervals);

  return 0;
}
