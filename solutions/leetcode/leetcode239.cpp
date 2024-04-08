#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //使用双向队列。
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            //如果窗口长度已经超过了k，则将最左边的元素移除
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            //从后往前移除所有队列中小于当前元素的元素
            while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            //在队列中添加当前元素
            dq.push_back(i);
            //如果窗口长度已经到达了k，则在结果中插入最大值(deque最前面的元素)
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};