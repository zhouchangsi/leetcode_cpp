/**
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * https://ahym1n4sq5.feishu.cn/docx/HE4adz9lmoXBbFxCLXDcfAHPnQh
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1, set2;
    for (auto& num : nums1) {
      set1.insert(num);
    }
    for (auto& num : nums2) {
      set2.insert(num);
    }
    return getIntersection(set1, set2);
  }

  vector<int> getIntersection(unordered_set<int>& set1,
                              unordered_set<int>& set2) {
    if (set1.size() > set2.size()) {
      return getIntersection(set2, set1);
    }
    vector<int> intersection;
    for (auto& num : set1) {
      if (set2.count(num)) {
        intersection.push_back(num);
      }
    }
    return intersection;
  }
};