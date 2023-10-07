#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace leetcode {
/**
 * @brief Parse a string to a vector of optional integers.
 *
 * @param str e.g. "[1,2,3,null,null,4,5]" or "1,2,3,null,null,4,5"
 * @return std::vector<std::optional<int>>
 */
std::vector<std::optional<int>> parse_leetcode_list(std::string str);

/**
 * @brief
 *
 * @param matrix e.g. "[[1,2,3],[4,5,6],[7,8,9]]"
 * @return vector<vector<int>>
 */
std::vector<std::vector<int>> parse_leetcode_matrix(std::string matrix);
}  // namespace leetcode
