class Solution {
public:
    // 要通过一个哈希表来记录，哪些数字出现过。
    // 但是这个题目我们可以直接用数组本身来作为哈希表。
    // 我们只需要把下标上的数字设为负数，就表明这个下标已经出现过。
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 首先便利。把当前的数字当做下标。将数组中对应下标的数字，变成负数。
        // nums[1] = 5, 表明5出现过。nums[5-1] = -nums[5-1]。
        for(auto n:nums) {
            // 要注意的是。当前的数字可能已经被前面的过程设为负数，要先取绝对值再减一作为下标。
            int index = abs(n) - 1;
            nums[index] = -abs(nums[index]);
        }
        // 第2次遍历看哪些下标对应是正数，就表明没有出现过。
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) ans.push_back(i+1); 
        }
        return ans;
    }
};