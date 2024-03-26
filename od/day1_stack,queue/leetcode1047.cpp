/*
 * https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * https://ahym1n4sq5.feishu.cn/docx/KZGXdkBHrofagqx1bf1cDiG6n9f
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for (auto c : s) {
            if (!st.empty() && c == st[st.size() - 1]) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        string res;
        for(auto c:st) {
            res+=c;
        }
        return res;
    }
};