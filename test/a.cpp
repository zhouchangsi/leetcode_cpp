#include <bits/stdc++.h>
using namespace std;

void solution(string line) {
  vector<string> airs;

  istringstream iss(line);
  string token;
  while (getline(iss, token, ',')) {
    airs.emplace_back(token);
  }

  sort(airs.begin(), airs.end(), [](const string &a, const string &b) {
    string ca = a.substr(0, 2);
    string cb = b.substr(0, 2);
    if (ca == cb) {
      return a.substr(2) < b.substr(2);
    }
    return ca < cb;
  });

  for (int i = 0; i < airs.size(); i++) {
    cout << airs[i];
    if (i != airs.size() - 1) {
      cout << ",";
    }
  }
}

int main() {
  // solution("CA3385,CZ6678,SC6508,DU7523,HK4456,MK0987");
  string line;
  getline(cin, line);
  solution(line);
  return 0;
}