/**
 * https://leetcode.cn/problems/FortPu/submissions/513338664/
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (val2index.count(val)) {
      return false;
    }
    int index = nums.size();
    nums.emplace_back(val);
    val2index[val] = index;
    return true;
  }

  bool remove(int val) {
    if (!val2index.count(val)) {
      return false;
    }
    int index = val2index[val];
    int last = nums.back();
    nums[index] = last;
    val2index[last] = index;
    nums.pop_back();
    val2index.erase(val);
    return true;
  }

  int getRandom() {
    int randomIndex = rand() % nums.size();
    return nums[randomIndex];
  }

 private:
  vector<int> nums;
  unordered_map<int, int> val2index;
};