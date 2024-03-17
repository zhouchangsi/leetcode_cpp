/**
 * https://og7kl7g6h8.feishu.cn/docx/KYasd0qGLoWjCSxeB0oc73GJneb
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Initialize a 2D dp array with dimensions n*2
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // Initialize dp[0] based on the first character of the string
    if (s[0] == 'A') {
        dp[0][0] = 0;  // No operation needed to end with 'A'
        dp[0][1] = 1;  // One operation needed to change 'A' to 'B'
    } else {
        dp[0][0] = 1;  // One operation needed to change 'B' to 'A'
        dp[0][1] = 0;  // No operation needed to end with 'B'
    }

    // Iterate through the string
    for (int i = 1; i < n; i++) {
        // If the current character is 'A'
        if (s[i] == 'A') {
            dp[i][0] = dp[i - 1][0];          // No change to end with 'A'
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;  // Change 'B' to 'A'
        }
        // If the current character is 'B'
        else {
            dp[i][0] = dp[i - 1][0] + 1;      // Change 'A' to 'B'
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);  // No change to end with 'B'
        }
    }

    // Get the minimum value from dp[n-1]
    int minOperations = min(dp[n - 1][0], dp[n - 1][1]);
    cout << minOperations << endl;

    return 0;
}
