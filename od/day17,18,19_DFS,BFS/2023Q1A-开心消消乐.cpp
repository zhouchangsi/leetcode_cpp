/**
 * https://og7kl7g6h8.feishu.cn/docx/Ss9QdEWYaooSdXx3ykbc4dHBnSe
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    auto grid = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    auto dirs = vector<pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
    function<void(int, int)> dfs = [&](int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        {
            return;
        }
        grid[i][j] = 0;
        for (auto &[dx, dy] : dirs)
        {
            dfs(i + dx, j + dy);
        }
    };

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count;
}