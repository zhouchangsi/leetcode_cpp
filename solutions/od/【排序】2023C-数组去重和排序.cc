#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> first, cnt;

struct cmp {
  const bool operator()(const int& a, const int& b) const {
    if (cnt[a] == cnt[b]) return first[a] < first[b];
    return cnt[a] > cnt[b];
  }
};

void solve(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    if (first.count(nums[i]) == 0) first[nums[i]] = i;
    cnt[nums[i]]++;
  }

  set<int, cmp> s(nums.begin(), nums.end());

  string out = "";
  for (auto i : s) out += to_string(i) + ",";
  out.pop_back();
  cout << out << '\n';
}

int main() {
  vector<int> nums = {1, 3, 3, 3, 2, 4, 4, 4, 5};
//   string num;
//   while (getline(cin, num, ',')) {
//     nums.push_back(stoi(num));
//   }
  solve(nums);
  return 0;
}