#include <bits/stdc++.h>
using namespace std;

void solution(vector<string> lines, int level, string target) {
  unordered_map<int, unordered_map<string, int>> m;
  for (auto line : lines) {
    stringstream ss(line);
    ss.ignore();
    string s;
    int l = 1;
    while (getline(ss, s, '/')) {
      m[l++][s]++;
    }
  }

  cout << m[level][target] << endl;
}

int main() {
  // solution(
  //     {
  //         "/huawei/computing/no/one",  //
  //         "/huawei/computing",         //
  //         "/huawei",                   //
  //         "/huawei/cloud/no/one",      //
  //         "/huawei/wireless/no/one"    //
  //     },
  //     2, "computing");
  int n;
  cin >> n >> ws;
  vector<string> lines(n);
  for (int i = 0; i < n; i++) {
    cin >> lines[i];
  }
  int level;
  string target;
  cin >> level >> target;
  solution(lines, level, target);
}