#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief https://og7kl7g6h8.feishu.cn/docx/VjK6dUSjpo77mVxkd3XcB7ZfnBh
 */
int
count_WuFu(vector<string>& wufu_list)
{
  vector<int> wufu_count(5, 0);
  for (const string& wufu : wufu_list) {
    for (int i = 0; i < wufu.length(); i++) {
      if (wufu[i] == '1') {
        wufu_count[i]++;
      }
    }
  }
  int minCount = INT_MAX;
  for (int count : wufu_count) {
    minCount = min(minCount, count);
  }
  return minCount;
}

/**
 * @brief https://og7kl7g6h8.feishu.cn/docx/Id77d9sFEopeCNxJmVJcFoNOnke
 */
int
max_distance_of_same_number(vector<int>& numbers)
{
  unordered_map<int, int> first_index_of;
  int max_distance = -1;
  for (int i = 0; i < numbers.size(); i++) {
    int current_number = numbers[i];
    if (first_index_of.find(current_number) == first_index_of.end()) {
      first_index_of[current_number] = i;
    } else {
      max_distance = max(max_distance, i - first_index_of[current_number]);
    }
  }
  return max_distance;
}