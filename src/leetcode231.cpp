#include "common_headers.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

TEST(leetcode231, case1) {
    Solution s;
    EXPECT_EQ(s.isPowerOfTwo(1), true);
    EXPECT_EQ(s.isPowerOfTwo(16), true);
    EXPECT_EQ(s.isPowerOfTwo(218), false);
}