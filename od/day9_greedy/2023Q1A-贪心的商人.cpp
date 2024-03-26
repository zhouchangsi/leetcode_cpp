// https://og7kl7g6h8.feishu.cn/docx/LHD9d8pkrouZBCx5SOEcLTpinLf
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int tmp = prices[i] - prices[i - 1];
        if (tmp > 0) {
            profit += tmp;
        }
    }

    return profit;
}

int main() {
    int n, days;
    cin >> n >> days;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> prices(days);
        for (int j = 0; j < days; j++) {
            cin >> prices[j];
        }
        ans += maxProfit(prices) * numbers[i];
    }

    cout << ans << endl;

    return 0;
}
