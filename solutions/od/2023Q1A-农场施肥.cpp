/**
 * https://og7kl7g6h8.feishu.cn/docx/Xjexdl4CuoDEY8xZyZccJv5KnHh
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 当能效为k时，需要多少天才能把全部 fields 施肥完毕
int calDays(int k, vector<int>& fields) {
  // 对于每一个field，都需要施肥 ceil(field / k) 天
  int sum = 0;
  for (int field : fields) {
    sum += ceil((double)field / k);
  }
  return sum;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> fields(m);
  for (int i = 0; i < m; i++) {
    cin >> fields[i];
  }

  // 特殊情况判断，如果农场数m大于天数n，不可能完成施肥，输出-1
  if (m > n) {
    cout << -1 << endl;
  } else {
    // 当能效取 1，需要 sum(fields) 天完成所有农田施肥
    // 当能效取 max(fields)，需要 m 天完成所有农田施肥
    // 左闭右开区间
    int left = 1, right = 0;
    for (int field : fields) {
      right = max(right, field);
    }

    // 左闭右开区间，退出循环时存在 left = right = mid
    // 循环不变量为left < right
    while (left < right) {
      // 计算 left 和 right 的平均值 mid
      int mid = (left + right) / 2;
      // 施肥天数比n天多，能效太低，left 右移
      // 退出循环时，left 恰好不满足if条件语句中
      // 即存在 calDays(left, fields) <= n
      // left是该式子成立的第一个整数，故left是为答案
      if (calDays(mid, fields) > n) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    // 输出 left 或 right 均为答案
    cout << left << endl;
  }

  return 0;
}
