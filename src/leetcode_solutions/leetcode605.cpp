#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    int last_flower_index = -1;
    for (int i = 0; i < size; i++) {
      if (flowerbed[i] == 1) {
        if (last_flower_index < 0) {
          count += i / 2;
        } else {
          count += (i - last_flower_index - 2) / 2;
        }
        last_flower_index = i;
      }
    }
    if (last_flower_index < 0) {
      count += (size + 1) / 2;
    } else {
      count += (size - last_flower_index - 1) / 2;
    }
    return count >= n;
  }
};

TEST(leetcode, solution) {

}