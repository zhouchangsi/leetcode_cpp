/**
 * https://leetcode.cn/problems/permutation-in-string/description/
 * https://r07na4yqwor.feishu.cn/docx/Sc1ldNoYtokQXNxtuKAcmx4ingh
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> need(26, 0), window(26, 0);
        for (const char& c : s1) {
            need[c - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            window[s2[i] - 'a']++;
        }
        if (window == need) {
            return true;
        }

        for (int l = 0, r = s1.size(); r < s2.size(); l++, r++) {
            window[s2[r] - 'a']++;
            window[s2[l] - 'a']--;
            if (window == need) {
                return true;
            }
        }
        return false;
    }
};