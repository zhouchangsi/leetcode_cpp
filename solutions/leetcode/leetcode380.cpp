// https://leetcode.com/problems/insert-delete-getrandom-o1/
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
    int last_val = nums.back();
    nums[index] = last_val;
    val2index[last_val] = index;
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