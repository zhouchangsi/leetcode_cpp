#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    const auto& [ma, da] = a;
    const auto& [mb, db] = b;
    return ma == mb ? da < db : ma > mb;
  }
};

int main() {
  int day_limit = 10, city_num = 2;
  string line = "1 1 2";
  istringstream iss(line);
  while (iss >> line) day_limit -= stoi(line);

  vector<pair<int, int>> md_pairs = {{120, 20}, {90, 10}};

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

  return 0;
}