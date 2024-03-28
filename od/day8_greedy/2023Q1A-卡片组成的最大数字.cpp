// https://og7kl7g6h8.feishu.cn/docx/Xntxd66enollm6x41BXcH61zn21
#include <bits/stdc++.h>
using namespace std;

void solution(vector<string> nums) {
  sort(nums.begin(), nums.end(),
       [](const string& a, const string& b) { return a + b > b + a; });
  copy(nums.begin(), nums.end(), ostream_iterator<string>(cout, ""));
};

int main() {
  //   string line = "4589,101,41425,9999";
  //   string line = "22,223";
  vector<string> nums;
  string line = "22,221";
  getline(cin, line);
  istringstream iss(line);
  while (getline(iss, line, ',')) nums.push_back(line);
  solution(nums);
}