#include <iostream>
#include <optional>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::nullopt;
using std::optional;
using std::stoi;
using std::string;
using std::vector;

namespace leetcode {
vector<optional<int>> parse_leetcode_list(string str) {
  if (str[0] == '[') {
    str = str.substr(1, str.size() - 2);
  }
  str += ",";
  vector<optional<int>> nodes;
  string token = "";
  int i = 0;
  do {
    auto c = str[i];
    if (c != ',') {
      token += c;
      continue;
    }
    nodes.push_back(token == "null" ? optional<int>(nullopt)
                                    : optional<int>(stoi(token)));
    token = "";
  } while (i++ < str.size());
  return nodes;
}

vector<vector<int>> parse_leetcode_matrix(string matrix) {
  // cut the first '[' and last ']'
  matrix = matrix.substr(1, matrix.size() - 2);
  vector<vector<int>> rows;
  string row = "";  // e.g. "1,2,3"
  int i = 0;
  do {
    auto c = matrix[i];
    if (c == '[') {
      row = "";
      continue;
    }
    if (c != ']') {
      row += c;
      continue;
    }
    row += c;
    auto optional_nums = parse_leetcode_list(row);
    vector<int> nums;
    for (auto num : optional_nums) {
      nums.push_back(num.value());
    }
    rows.push_back(nums);
  } while (i++ < matrix.size());
  return rows;
}

};  // namespace leetcode