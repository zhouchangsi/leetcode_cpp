/**
 * https://og7kl7g6h8.feishu.cn/docx/ZLfNdmszho3j44x8Z4FcKyubnxe
*/

#include <iostream>
#include <vector>
using namespace std;

int DIRECTIONS[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;
vector<string> grid;
vector<vector<int>> checkList;
int ans = 0;

void dfs(int x, int y, int &curValue) {
    checkList[x][y] = 1;
    curValue += grid[x][y] - '0';

    for (auto dir : DIRECTIONS) {
        int nxt_x = x + dir[0];
        int nxt_y = y + dir[1];

        if (nxt_x >= 0 && nxt_x < n && nxt_y >= 0 && nxt_y < m &&
            grid[nxt_x][nxt_y] != '0' && checkList[nxt_x][nxt_y] == 0) {
                dfs(nxt_x, nxt_y, curValue);
        }
    }
}

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        grid.push_back(line);
    }

    n = grid.size();
    m = grid[0].size();
    checkList.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '0' && checkList[i][j] == 0) {
                int curValue = 0;
                dfs(i, j, curValue);
                ans = max(ans, curValue);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
