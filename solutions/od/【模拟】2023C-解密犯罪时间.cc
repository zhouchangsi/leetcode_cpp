#include <bits/stdc++.h>
using namespace std;

struct Time {
  vector<int> part;
  Time(string s) {
    part.resize(4);
    part[0] = s[0] - '0';
    part[1] = s[1] - '0';
    part[2] = s[3] - '0';
    part[3] = s[4] - '0';
  }

  void to_next() {
    int h = part[0] * 10 + part[1];
    int m = part[2] * 10 + part[3];
    if (m == 59) {
      m = 0;
      h++;
      h %= 24;
    } else {
      m++;
    }
    part[0] = h / 10;
    part[1] = h % 10;
    part[2] = m / 10;
    part[3] = m % 10;
  }

  string str() {
    stringstream ss;
    ss << to_string(part[0]) << to_string(part[1]) << ":"  //
       << to_string(part[2]) << to_string(part[3]);
    return ss.str();
  }
};

void solve(string s) {
  Time t(s);
  set<int> nums(t.part.cbegin(), t.part.cend());

  int n = 24 * 60;
  while (n--) {
    t.to_next();
    bool all_in_nums = all_of(t.part.cbegin(), t.part.cend(),
                              [&](int p) { return nums.count(p); });

    if (all_in_nums) {
      cout << t.str() << endl;
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //   solve("18:52");
  string line;
  cin >> line;
  solve(line);
}