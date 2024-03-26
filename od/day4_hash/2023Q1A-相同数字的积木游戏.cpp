// https://og7kl7g6h8.feishu.cn/docx/Id77d9sFEopeCNxJmVJcFoNOnke
#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> nums) {
  int n = nums.size();
  unordered_map<int, int> last_index, first_index;
  for (int i = 0; i < n; i++) last_index[nums[i]] = i;
  for (int i = n - 1; i >= 0; i--) first_index[nums[i]] = i;

  int max_distance = -1;
  for (auto num : nums) {
    int d = last_index[num] - first_index[num];
    if (d == 0) continue;
    max_distance = max(max_distance, d);
  }

  cout << max_distance << '\n';
}

int main() {
  //   solution({1, 2, 3, 1, 4});
  int n;
  cin >> n;
  vector<int> nums;
  int num;
  while (cin >> num) nums.push_back(num);
  solution(nums);
  return 0;
}