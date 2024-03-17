/**
 * https://leetcode-cn.com/problems/ransom-note/
 * https://ahym1n4sq5.feishu.cn/docx/OeZkdRHmkoyj1jxkEJlcL5k8ngg
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (auto & c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto & c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
