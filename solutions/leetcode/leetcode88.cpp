// https://leetcode.com/problems/merge-sorted-array/
// https://ahym1n4sq5.feishu.cn/docx/QmqGdGQiMoVm22xyz9fcZUcTnUe
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index_1 = m - 1, index_2 = n - 1, index_answer = m + n - 1;
    while (index_1 >= 0 && index_2 >= 0) {
      if (nums1[index_1] > nums2[index_2]) {
        nums1[index_answer--] = nums1[index_1--];
      } else {
        nums1[index_answer--] = nums2[index_2--];
      }
    }
    while (index_2 >= 0) {
      nums1[index_answer--] = nums2[index_2--];
    }
  }
};