/**
 * https://og7kl7g6h8.feishu.cn/docx/KXvAd7WosoQnFdxQH1hcOYpLnCg
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 【DFS/BFS】2023C-可以组成网络的服务器
 * https://og7kl7g6h8.feishu.cn/docx/Z3kvd4C65o5DsgxYn7ocfl8qnic
 */
void dfs_local_server(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int &count)
{
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;
    if (grid[i][j] == 0)
        return;
    if (visited[i][j] == 1)
        return;
    visited[i][j] = 1;
    count++;
    dfs_local_server(grid, visited, i - 1, j, count);
    dfs_local_server(grid, visited, i + 1, j, count);
    dfs_local_server(grid, visited, i, j - 1, count);
    dfs_local_server(grid, visited, i, j + 1, count);
}

int max_local_server(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int count = 0;
    dfs_local_server(grid, visited, 0, 0, count);
    return count;
}

/**
 * 【DFS/BFS】2023C-图像物体的边界
 */
class ImageBoundary
{
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    void dfs_boundary(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            return;
        }
        grid[i][j] = 3;

        for (auto [dx, dy] : directions)
        {
            int x = i + dx, y = j + dy;
            dfs_boundary(grid, x, y);
        }
    }
    int count_boundary(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 5)
                    continue;
                for (auto [dx, dy] : directions)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 || x < m || y || 0 || y < n)
                        continue;
                    grid[x][y] = 3;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 3)
                {
                    dfs_boundary(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

/**
 * 【DFS/BFS】2023C-精准核酸检测
 */
void dfs(vector<vector<int>> &grid, vector<int> &visited, int patient_id, int &count)
{
    int m = grid.size(), n = grid[0].size();
    if (visited[patient_id] == 1)
        return;
    if (patient_id < 0 || patient_id >= m)
        return;
    count++;
    vector<int> &contacts = grid[patient_id];
    for (int i = 0; i < n; i++)
    {
        if (contacts[i] == 1)
        {
            visited[patient_id] = 1;
            dfs(grid, visited, i, count);
        }
    }
}

int count_to_check(vector<vector<int>> &grid, vector<int> &infected)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> visited(m);
    int count = 0;

    for (auto patient_id : infected)
    {
        dfs(grid, visited, patient_id, count);
    }

    return count;
}

/**
 * 【DFS/BFS】2023C-寻找最富裕的小家庭
 */
int max_richest_family(vector<int> &money, vector<vector<int>> &family)
{
    int family_num;                    // input
    vector<int> money(family_num + 1); // input

    vector<int> family_money(money.begin(), money.end());

    int max_money = 0;
    for (int i = 0; i < family_num; i++)
    {
        int father; // input
        int child;  // input
        cin >> father >> child;
        family_money[father] += money[child];
        max_money = max(max_money, money[father]);
    }
    return *max_element(family_money.begin(), family_money.end());
}