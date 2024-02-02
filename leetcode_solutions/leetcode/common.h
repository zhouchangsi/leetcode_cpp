#pragma once
#include <algorithm>
#include <optional>
#include <string>
#include <vector>

namespace leetcode {
/**
 * @brief Check if a string is a integer
 * e.g. "123", "-123", "0", "0123", "+123"
 * @return true
 * @return false
 */
bool inline is_integer(const std::string& s)
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
template<typename T>
inline std::vector<std::optional<T>>
parse_leetcode_list(std::string str)
{
  if (str.empty()) {
    return {};
  }
  if (str[0] == '[') {
    // cut the first '[' and last ']'
    str = str.substr(1, str.size() - 2);
  }
  str += ",";
  std::vector<std::optional<T>> nodes;
  std::string token = "";
  int i = 0;
  do {
    auto c = str[i];
    if (c != ',') {
      token += c;
      continue;
    }
    nodes.push_back(token == "null" ? std::optional<T>(std::nullopt)
                                    : std::optional<T>(std::stoi(token)));
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
template<typename T>
inline std::vector<std::vector<T>>
parse_leetcode_matrix(std::string matrix)
{
  if (matrix.empty()) {
    return {};
  }
  // cut the first '[' and last ']'
  matrix = matrix.substr(1, matrix.size() - 2);
  std::vector<std::vector<T>> rows;
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
    auto optional_nums = parse_leetcode_list<T>(row);
    std::vector<T> nums;
    for (auto num : optional_nums) {
      nums.push_back(num.value());
    }
    rows.push_back(nums);
  } while (i++ < matrix.size());
  return rows;
}

};