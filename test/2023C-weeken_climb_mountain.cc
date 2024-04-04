// https://og7kl7g6h8.feishu.cn/docx/Kyqsdy4yDo7E1nxz8fmcvOHnncg
// 【BFS】2023C-周末爬山
// 题目描述与示例
// 题目描述：
// 周末小明准备去爬山锻炼，0代表平地，山的高度使用1到9来表示，小明每次爬山或下山高度只能相差k及k以内，每次只能上下左右一个方向上移动一格，小明从左上角(0,0)位置出发
// 输入描述
// 第一行输入m n k(空格分隔)
// 代表 m*n
// 的二维山地图，k为小明每次爬山或下山高度差的最大值，然后接下来输入山地图，一共
// m行n列，均以空格分隔。 取值范围： 0 < m ≤ 500 0 < n ≤ 500 0 < k < 5 输出描述
// 请问小明能爬到的最高峰多高，到该最高峰的最短步数，输出以空格分隔。
// 同高度的山峰输出较短步数。
// 如果没有可以爬的山峰，则高度和步数都返回0。
// 备注：所有用例输入均为正确格式，且在取值范围内，考生不需要考虑不合法的输入格式。
// 示例1
// 输入
// 5 4 1
// 0 1 2 0
// 1 0 0 0
// 1 0 1 2
// 1 3 1 0
// 0 0 0 9

// 输入
// 2 2
// 说明
// 根据山地图可知，能爬到的最高峰在(0,2)位置，高度为2，最短路径为(0,0)-(0,1)-(0,2)，最短步数为2。
// 示例2
// 输入
// 5 4 3
// 0 0 0 0
// 0 0 0 0
// 0 9 0 0
// 0 0 0 0
// 0 0 0 9

// 输入
// 0 0
// 说明
// 根据山地图可知，每次爬山距离3，无法爬到山峰上，步数为0。

#include <bits/stdc++.h>
using namespace std;

auto dirs = vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(int k, vector<vector<int>> height) {
  int n = height.size(), m = height[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  int max_height = 0, min_step = 0, level = 0;
  while (!q.empty()) {
    level++;
    int size = q.size();
    while (size--) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m ||  //
            visited[nx][ny] ||                         //
            abs(height[nx][ny] - height[x][y]) > k     //
        ) {
          continue;
        }
        visited[nx][ny] = 1;
        q.push({nx, ny});
        if (height[nx][ny] > max_height) {
          max_height = height[nx][ny];
          min_step = level;
        } else if (height[nx][ny] == max_height) {
          min_step = min(min_step, level);
        }
      }
    }
  }
  if (max_height > height[0][0]) {
    cout << max_height << " " << min_step << endl;
  } else {
    cout << 0 << " " << 0 << endl;
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> height(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> height[i][j];
    }
  }
  solve(k, height);
  return 0;
}
