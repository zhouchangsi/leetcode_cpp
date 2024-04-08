// http
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int quickselect(vector<int>& nums, int l, int r, int k) {
    if (l == r) return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j) {
      do i++;
      while (nums[i] < partition);
      do j--;
      while (nums[j] > partition);
      if (i < j) swap(nums[i], nums[j]);
    }
    if (k <= j)
      return quickselect(nums, l, j, k);
    else
      return quickselect(nums, j + 1, r, k);
  }

  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k);
  }
};

class Solution {
 public:
  void adjMinHeap(vector<int>& nums, int root, int heapsize) {
    int left = root * 2 + 1, right = root * 2 + 2, minimum = root;
    if (left < heapsize && nums[left] < nums[minimum]) minimum = left;
    if (right < heapsize && nums[right] < nums[minimum]) minimum = right;
    if (minimum != root) {
      swap(nums[minimum], nums[root]);
      adjMinHeap(nums, minimum, heapsize);
    }
  }

  void buildMinHeap(vector<int>& nums, int k) {
    for (int i = k / 2 - 1; i >= 0; i--) adjMinHeap(nums, i, k);
  }
  int findKthLargest(vector<int>& nums, int k) {
    buildMinHeap(nums, k);
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] < nums[0]) continue;
      swap(nums[0], nums[i]);
      adjMinHeap(nums, 0, k);
    }
    return nums[0];
  }
};