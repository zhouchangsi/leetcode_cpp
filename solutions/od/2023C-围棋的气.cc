#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    hash<int> int_hasher;
    return int_hasher(v.first) ^ int_hasher(v.second);
  }
};

using pair_set = unordered_set<pair<int, int>, pair_hash>;

int main() {
  pair_set b_pos, w_pos, b_air, w_air;
  string black_line = "0 5 8 9 9 10", white_line = "5 0 9 9 9 8";
  getline(cin, black_line);
  getline(cin, white_line);
  stringstream ss_b(black_line), ss_w(white_line);
  int i, j;
  while (ss_b >> i >> j) b_pos.insert({i, j});
  while (ss_w >> i >> j) w_pos.insert({i, j});

  // for(auto [i, j]:b_pos) cout << i << ',' << j << ' ';
  // for(auto [i, j]:w_pos) cout << i << ',' << j << ' ';

  auto is_valid = [&b_pos, &w_pos](pair_set &air, const int i,
                                   const int j) -> bool {
    if (i < 0 || i > 18 || j < 0 || j > 18) return false;
    if (b_pos.count({i, j})) return false;
    if (w_pos.count({i, j})) return false;
    if (air.count({i, j})) return false;
    air.insert({i, j});
    return true;
  };
  int count_b = 0, count_w = 0;
  const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (auto [i, j] : b_pos) {
    for (auto [dx, dy] : directions) {
      if (is_valid(b_air, i + dx, j + dy)) count_b++;
    }
  }
  for (auto [i, j] : w_pos) {
    for (auto [dx, dy] : directions) {
      if (is_valid(w_air, i + dx, j + dy)) count_w++;
    }
  }
  cout << count_b << ' ' << count_w << endl;
}