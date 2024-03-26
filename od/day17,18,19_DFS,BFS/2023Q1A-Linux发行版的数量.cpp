/**
 * https://og7kl7g6h8.feishu.cn/docx/QJrYdFGcro67xfxhuy6cpanMnog
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    int ans = 0;
    vector<int> checkList(n, 0);

    for (int i = 0; i < n; i++) {
        if (checkList[i] == 0) {
            queue<int> q;
            q.push(i);
            checkList[i] = 1;
            int curNum = 0;

            while (!q.empty()) {
                int x = q.front();
                q.pop();
                curNum++;

                for (int y = 0; y < n; y++) {
                    if (x != y && checkList[y] == 0 && isConnected[x][y] == 1) {
                        q.push(y);
                        checkList[y] = 1;
                    }
                }
            }

            ans = max(ans, curNum);
        }
    }

    cout << ans << endl;
    return 0;
}
