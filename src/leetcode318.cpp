#include "common_headers.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
        }

        int maxProd = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }

        return maxProd;    
    }
};


TEST(leetcode318, case1) {
    Solution s;
    EXPECT_EQ(s.maxProduct(vector<string>({"abcw","baz","foo","bar","xtfn","abcdef"})), 16);
    EXPECT_EQ(s.maxProduct(vector<string>({"a","ab","abc","d","cd","bcd","abcd"})), 4);
    EXPECT_EQ(s.maxProduct(vector<string>({"a","aa","aaa","aaaa"})), 0);
}