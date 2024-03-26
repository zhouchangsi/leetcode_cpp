/**
 * https://og7kl7g6h8.feishu.cn/docx/DirWdLYzRo3sQPx1gY7cpIMfn7d
*/
#include <iostream>
#include <vector>

using namespace std;

int climb_num(int n) {
    if (n <= 2) { return 1; } 
    auto dp = vector<int>(n + 1, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-3];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << climb_num(n) << endl;
    return 0;
}
