// https://leetcode-cn.com/problems/group-anagrams/
// https://ahym1n4sq5.feishu.cn/docx/DelAduSDeoDAykxjnYwclo8Pn4d
#include "leetcode/env.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }
};