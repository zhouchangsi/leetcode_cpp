#pragma once
#include <string>
#include <vector>
#include <optional>

namespace leetcode {
/**
 * @brief Check if a string is a integer
 * e.g. "123", "-123", "0", "0123", "+123"
 * @return true
 * @return false
 */
bool
is_integer(const std::string& s)
{
  if (s.empty()) {
    return false;
  }
  auto it = s.begin();
  if (*it == '+' || *it == '-') {
    it++;
  }
  if (it == s.end()) {
    return false;
  }
  return std::all_of(it, s.end(), ::isdigit);
}

/**
 * @brief Parse a string to a vector of optional integers.
 *
 * @param str e.g. "[1,2,3,null,null,4,5]" or "1,2,3,null,null,4,5"
 * @return std::vector<std::optional<int>>
 */
std::vector<std::optional<int>>
parse_leetcode_list(std::string str)
{
  if (str[0] == '[') {
    // cut the first '[' and last ']'
    str = str.substr(1, str.size() - 2);
  }
  str += ",";
  std::vector<std::optional<int>> nodes;
  std::string token = "";
  int i = 0;
  do {
    auto c = str[i];
    if (c != ',') {
      token += c;
      continue;
    }
    nodes.push_back(token == "null" ? std::optional<int>(std::nullopt)
                                    : std::optional<int>(std::stoi(token)));
    token = "";
  } while (i++ < str.size());
  return nodes;
}

/**
 * @brief Parse a string to a matrix.
 *
 * @param matrix e.g. "[[1,2,3],[4,5,6],[7,8,9]]"
 * @return vector<vector<int>>
 */
std::vector<std::vector<int>>
parse_leetcode_matrix(std::string matrix)
{
  // cut the first '[' and last ']'
  matrix = matrix.substr(1, matrix.size() - 2);
  std::vector<std::vector<int>> rows;
  std::string row = ""; // e.g. "1,2,3"
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
    std::vector<int> nums;
    for (auto num : optional_nums) {
      nums.push_back(num.value());
    }
    rows.push_back(nums);
  } while (i++ < matrix.size());
  return rows;
}

};