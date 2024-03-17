/**
 * https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 * https://r07na4yqwor.feishu.cn/docx/ZhXxdvpQFoZOcTxtsDIc5g5vn7d
*/
#include "../leetcode/leetcode.h"

class Solution {
    unordered_set<char> vowels_set = {'a', 'e', 'i', 'o', 'u'};
    bool is_vowel(char c) {
        return vowels_set.count(c) > 0;
    }
public:
    int maxVowels(string s, int k) {
        // first window
        int vowels_num = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowel(s[i])) {
                vowels_num++;
            }
        }
        int ans = vowels_num;
        int size = s.size();
        for (int l = 0, r = k; r < size; l++, r++) {
            if(is_vowel(s[r])) {
                vowels_num++;
            }
            if(is_vowel(s[l])) {
                vowels_num--;
            }
            ans = max(ans, vowels_num);
        }
        return ans;
    }
};