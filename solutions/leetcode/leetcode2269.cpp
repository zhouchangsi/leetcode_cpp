/**
 * https://leetcode.cn/problems/find-the-k-beauty-of-a-number/submissions/511025841/
 * https://r07na4yqwor.feishu.cn/docx/KIFQdC1f3oScVAx1Mg9c5blDn4m
*/
#include "../leetcode.h"

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num_str = to_string(num); // ?
        int ans = 0;
        
        string sub_str = num_str.substr(0, k);
        if (stoi(sub_str) != 0 && num % stoi(sub_str) == 0) {
            ans++;
        }
        
        for (int i = k; i < num_str.size(); i++) {
            sub_str = sub_str.substr(1) + num_str[i];
            if (stoi(sub_str) != 0 && num % stoi(sub_str) == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
