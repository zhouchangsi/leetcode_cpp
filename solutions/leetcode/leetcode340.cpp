// https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        const int& n = s.size();
        unordered_map<char, int> m;
        int l = 0, r = 0;
        int max_len = 0;
        while (r < n) {
            m[s[r]]++;
            while (m.size() > k) {
                m[s[l]]--;
                if (m[s[l]] == 0) {
                    m.erase(s[l]);
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};