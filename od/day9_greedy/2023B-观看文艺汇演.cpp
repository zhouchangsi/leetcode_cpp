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

bool compareIntervals(const Interval& a, const Interval& b) {
  return a.start < b.start;
}

int main() {
  int N;
  cin >> N;

  vector<Interval> intervals;
  for (int i = 0; i < N; ++i) {
    int start, during;
    cin >> start >> during;
    int end = start + during + 15;
    intervals.push_back(Interval(start, end));
  }

  sort(intervals.begin(), intervals.end(), compareIntervals);

  int ans = 0;
  int preEnd = -1e9;

  for (const auto& interval : intervals) {
    int start = interval.start;
    int end = interval.end;

    if (start >= preEnd) {
      ans++;
      preEnd = end;
    } else if (start < preEnd && preEnd <= end) {
      continue;
    } else if (preEnd > end) {
      preEnd = end;
    }
  }

  cout << ans << endl;

  return 0;
}
