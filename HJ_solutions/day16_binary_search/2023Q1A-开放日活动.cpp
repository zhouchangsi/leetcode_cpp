/**
 * https://og7kl7g6h8.feishu.cn/docx/Q9ILdheU6ompXdxmneucN3cLnog
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int getSumWithMaxCap(int maxCapacity, const vector<int>& bucketBallNums) {
    int sum = 0;
    for (int num : bucketBallNums) {
        sum += min(num, maxCapacity);
    }
    return sum;
}

int main() {
    int SUM, n;
    cin >> SUM >> n;
    vector<int> bucketBallNums(n);
    for (int i = 0; i < n; i++) {
        cin >> bucketBallNums[i];
    }

    if (accumulate(bucketBallNums.begin(), bucketBallNums.end(), 0) < SUM) {
        cout << "[]" << endl;
    } else {
        int left = 1;
        int right = *max_element(bucketBallNums.begin(), bucketBallNums.end()) + 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (getSumWithMaxCap(mid, bucketBallNums) > SUM) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int maxCapacity = left - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = (bucketBallNums[i] < maxCapacity) ? 0 : (bucketBallNums[i] - maxCapacity);
        }

        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << ans[i];
            if (i != n - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
