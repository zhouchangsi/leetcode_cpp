#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (auto s : strs) {
            int i = 0;
            while (i < s.size() && i < prefix.size() && s[i] == prefix[i])
                i++;
            prefix = prefix.substr(0, i);
        }

        return prefix;
    }
};