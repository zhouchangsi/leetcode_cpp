/**
 * https://og7kl7g6h8.feishu.cn/docx/IQn7dOD6GojFeGxNuF5c2oPdnIb
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int DIRECTIONS[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> checkList(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (checkList[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({i, j});
                checkList[i][j] = 1;
                int area = 0;

                while (!q.empty()) {
                    pair<int, int> point = q.front();
                    q.pop();
                    int x = point.first;
                    int y = point.second;
                    area++;

                    for (auto dir : DIRECTIONS) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                            checkList[nx][ny] == 0 && abs(grid[x][y] - grid[nx][ny]) <= 1) {
                            q.push({nx, ny});
                            checkList[nx][ny] = 1;
                        }
                    }
                }

                ans = max(ans, area);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
