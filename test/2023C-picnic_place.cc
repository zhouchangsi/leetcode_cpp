// https://og7kl7g6h8.feishu.cn/docx/PIHpdnCBaoqfZvxYDmHcvZ95nMF
// 2023C-聚餐地点
// 题目描述与示例
// 题目描述
// 小华和小为是很好的朋友，他们约定周末一起吃饭，通过手机交流，他们在地图上选择了很多聚餐地点
// （由于自然地形等原因，部分聚餐地点不可达），求小华和小为都能达到的聚餐地点有多少个。

// 输入描述
// 第一行输入 m 和 n，m 表示地图长度，n 表示地图宽度
// 第二行开始具体输入地图信息，地图信息包括
// 0 为通畅的道路
// 1 为障碍物（且仅 1 为障碍物）
// 2 为小华或小为，地图中必定有且仅有两个（非障碍物）
// 3 为被选中的聚餐地点（非障碍物）

// 输出描述
// 可以两方都到达的聚餐地点的数量，行末无空格

// 补充说明
// 地图长宽为m和n,4 <= m <= 100 ，4 <= n <= 100
// 聚餐的地点数量为k，则1 < k <= 100

// 示例
// 输入
// 4 4
// 2 1 0 3
// 0 1 2 1
// 0 3 0 0
// 0 0 0 0
// 输出
// 2
// 备注
// 第一行输入地图的长宽为4和4
// 第二行开始为具体的地图，其中：
// 3 代表小华和小明的聚餐地点；
// 2 代表小华或小明（确保有2个）；
// 0 代表可以通行的位置；
// 1 代表不可以出行的位置。
// 此时2者都能达到的聚餐位置有两处

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));
  int sx, sy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        sx = i;
        sy = j;
        break;
      }
    }
  }

  bool is_can_reach = false;
  int count = 0;
  function<void(int, int)> dfs = [&](int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m ||  // 越界
        grid[x][y] == 1 || visited[x][y]       // 障碍物或者已经访问过
    ) {
      return;
    }
    visited[x][y] = 1;
    if (grid[x][y] == 2) {
      is_can_reach = true;
    }
    if (grid[x][y] == 3) {
      count++;
    }
    dfs(x + 1, y), dfs(x - 1, y), dfs(x, y + 1), dfs(x, y - 1);
  };

  dfs(sx, sy);

  cout << (is_can_reach ? count : 0) << endl;
}

int main() {
  //   solve({
  //       {2, 1, 0, 3},  //
  //       {0, 1, 2, 1},  //
  //       {0, 3, 0, 0},  //
  //       {0, 0, 0, 0}   //
  //   });
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  solve(map);
}