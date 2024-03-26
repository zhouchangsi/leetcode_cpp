/**
 * https://og7kl7g6h8.feishu.cn/docx/Fiv6dtHbWo0qDUxE5HwciJnvnNg
 */
#include <bits/stdc++.h>
using namespace std;

const vector<int> get_first_higher(int n, std::vector<int>& heights) {
  vector<int> first_higher(n, 0);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && heights[i] > heights[s.top()]) {
      first_higher[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  return first_higher;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  const vector<int>& first_hight = get_first_higher(n, heights);

  for (int i = 0; i < n; i++) {
    cout << first_hight[i] << " ";
  }

  return 0;
}