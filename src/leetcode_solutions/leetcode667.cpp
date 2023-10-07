#include "common_headers.h"

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> answer;
        for (int i = 1; i < n - k; ++i) {
            answer.push_back(i);
        }
        for (int i = n - k, j = n; i <= j; ++i, --j) {
            answer.push_back(i);
            if (i != j) {
                answer.push_back(j);
            }
        }
        return answer;
    }
};

TEST(leetcode667, case1) {
  Solution s;
  EXPECT_EQ(s.constructArray(3, 1), vector<int>({1, 2, 3}));
  EXPECT_EQ(s.constructArray(3, 2), vector<int>({1, 3, 2}));
}