#include <bits/stdc++.h>
using namespace std;

int count_mountains(vector<int> heights) {
  int n = heights.size();
  int count = 0;
  if (n == 0) return 0;
  if (n == 1) return heights[0] > 0 ? 1 : 0;
  if (heights[0] > heights[1]) count++;
  if (heights[n - 1] > heights[n - 2]) count++;
  for (int i = 1; i < n - 1; i++) {
    if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) {
      count++;
    }
  }
  return count;
}

int main() {
  string line = "0,1,4,3,1,0,0,1,2,3,1,2,1,0";
  getline(cin, line);
  stringstream ss(line);
  string heights;
  vector<int> tokens;
  while (getline(ss, heights, ',')) {
    tokens.push_back(stoi(heights));
  }

  cout << count_mountains(tokens) << endl;

  return 0;
}