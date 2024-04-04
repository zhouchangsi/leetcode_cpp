#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
  // 输入也易错
  int insert_size;  // 要存储的内存大小
  cin >> insert_size;

  vector<vector<int> > intervals;
  // 已分配的内存首地址以及大小
  int start;       // 起始地址
  int memorySize;  // 存储的大小
  while (cin >> start >> memorySize) {
    if (cin.fail()) {
      break;
    }
    intervals.push_back(
        {start,
         start + memorySize});  // 存储一个已存储的空间的起始地址和结束地址；
  }

  sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {  // 默认升序
    return a[0] >
           b[0];  // 容器中0为起始位置，1为结束地址，就是按照我们的查找习惯进行排序
  });

  // 验证是否存在重复覆盖的情况
  bool isoverlap = 0;
  for (int i = 1; i < intervals.size(); i++) {
    int start = intervals[i][0];
    int preend = intervals[i - 1][1];
    if (start <
        preend) {  // 注意此处start不用等于preend，因为end处并不占用，注意这个细节
      isoverlap = 1;
      break;
    }
  }
  int ans = -1;
  if (isoverlap == true) {
    cout << -1 << endl;
  } else {
    // 让首位和末尾也满足这个条件
    intervals.insert(intervals.begin(), {-1, 0});
    intervals.push_back({100, 101});

    int freesize = 100;  // 设置为初始最大空间
    for (int i = 0; i < intervals.size(); i++) {
      // 怎么计算空间大小?用前一个的已占用的空间的end - 后一个已占用的start
      int free_start = intervals[i][1];
      int free_end = intervals[i + 1][0];
      int now_content = free_end - free_start;  // 当前的空间

      // 找到最合适的空间进行存放，找到最小且大于插入内容的起始
      if (now_content < freesize && now_content > insert_size) {
        ans = free_start;
        freesize = now_content;  // 找到最小的适合的空间
      }
    }
  }

  cout << ans << endl;

  return 0;
}