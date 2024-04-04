class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int r = 1; r <= n; ++r) {
            for (int l = 0; l < r; ++l) {
                if (dp[l] && wordSet.count(s.substr(l, r - l))) {
                    dp[r] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};