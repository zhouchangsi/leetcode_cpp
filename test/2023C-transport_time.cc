// https://og7kl7g6h8.feishu.cn/docx/E78PdBoojoFCoGxsvy5cfVq2nCe

// 题目描述与示例
// 题目描述
// M (1 <= M <= 20)辆车需要在一条不能超车的单行道到达终点，起点到终点的距离为N
// (1 <= N <= 400)
// 速度快的车追上前车后，只能以前车的速度继续行驶，求最后一车辆到达目的地花费的时间。
// 注:每辆车固定间隔1小时出发，比如第一辆车0时出发，第二辆车1时出发，依次类推

// 输入描述
// 第一行两个数字：M N分别代表车辆数和到终点的距离，以空格分隔。
// 接下来M行，每行1个数字 S，代表每辆车的速度。0 < S < 30

// 输出描述
// 输出:最后一辆车到达目的地花费的时间。

// 示例
// 输入
// 2 11
// 3
// 2

// 输出
// 5.5
// 说明
// 2辆车，距离11，0时出发的车速度快，1时出发的车慢，达到目的地花费5.5

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, distance;
  cin >> n >> distance;
  vector<int> speed(n);
  for (int i = 0; i < n; i++) {
    cin >> speed[i];
  }
  double last_arrived = 0;
  for (int i = 0; i < n; i++) {
    int start_time = i;
    double time = static_cast<double>(distance) / speed[i] + start_time;
    // 最后一辆车到达终点的时间，实际上也取决于所有车中花费最多时间的那辆车。
    last_arrived = max(last_arrived, time);
  }
  cout << last_arrived - (n - 1) << endl;
  return 0;
}