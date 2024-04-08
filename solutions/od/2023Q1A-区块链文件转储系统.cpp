/**
 * https://og7kl7g6h8.feishu.cn/docx/J07dd1cWko2AfKxcRSWcTy7ln4y
 */
#include <bits/stdc++.h>
using namespace std;

void slide_window(int limit, string file_line) {
  vector<int> file_size_list;
  stringstream ss(file_line);
  string file_size;
  while (getline(ss, file_size, ' ')) {
    file_size_list.push_back(stoi(file_size));
  }

  int n = file_size_list.size();
  int l = 0, r = 0;
  int sum = 0;
  int max_sum = 0;
  while (r < n) {
    sum += file_size_list[r];
    while (sum > limit) {
      sum -= file_size_list[l];
      l++;
    }
    max_sum = max(max_sum, sum);
    r++;
  }
  cout << max_sum << endl;
}

int main() {
  //   slide_window(1000, "100 300 500 400 400 150 100");

  string limit;
  string file_line;
  getline(cin, limit);
  getline(cin, file_line);
  slide_window(stoi(limit), file_line);
  return 0;
}