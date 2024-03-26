// https://og7kl7g6h8.feishu.cn/docx/U72rdSNGBoO3rFxE2WjcgZ4XnZd
#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> nums) {
  int n = nums.size();

  auto l = nums.begin();
  auto r = find(nums.begin(), nums.end(), 1);
  if (r == nums.end()) {
    cout << n - 1;
    return;
  }
  int max_distance = distance(l, r);

  while (r != nums.end()) {
    l = r;
    r = find(r + 1, nums.end(), 1);
    if (r == nums.end()) break;
    int d = distance(l, r) / 2;
    max_distance = max(max_distance, d);
  }
  max_distance = max(
      static_cast<int>(distance(l, r) - 1),  // -1是因为nums.end()不是合法的位置
      max_distance);

  cout << max_distance;
};

int main() {
  vector<int> nums;

  //   string line = "1,0,0,0,0,1,0,0,1,0,1";
  string line = "1,1,0,0,1,0,0,0,0,0,1";
  getline(cin, line);
  istringstream iss(line);
  while (getline(iss, line, ',')) nums.emplace_back(stoi(line));

  solution(nums);
}