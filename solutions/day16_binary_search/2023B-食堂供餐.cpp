/**
 * https://og7kl7g6h8.feishu.cn/docx/HrFRdlddJoZ3z5xGct4c5vmdnjg
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 该函数用于检查：当选择单位时间出餐份数为 speed 时，能否完成供餐
bool checkAvailable(int M, vector<int>& nums, int speed) {
  // 初始化剩余餐数为 M
  int rest = M;
  // 遍历每分钟前来的人数 num
  for (int num : nums) {
    // 如果剩余餐数小于本分钟前来人数 num
    // 有员工需要等待，无法完成供餐，直接返回 false
    if (rest < num) {
      return false;
    }
    // 本分钟可以完成供餐，那么剩余餐数减去就餐人数
    rest -= num;
    // 剩余餐数加上该分钟的出餐，可以提供给后续就餐的员工
    rest += speed;
  }
  // 在上述循环中没有返回 false，说明没有出现员工需要等待的情况
  // 所有人都可以无需等待完成就餐，供餐完成，返回 true
  return true;
}

int main() {
  // N 分钟
  int N;
  cin >> N;
  // 初始已有 M 份餐
  int M;
  cin >> M;
  // N 分钟前来就餐的员工数目
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  // 出餐速度最大值取 *max_element(nums.begin(), nums.end())，一定能够满足
  // 每个员工都不需要等餐就可以就餐
  int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;

  // 左闭右开区间，退出循环时存在 left = right = mid
  // 循环不变量为 left < right
  while (left < right) {
    // 计算 left 和 right 的平均值 mid
    int mid = (left + right) / 2;
    // 可以完成供餐，说明供餐速度较大，可以缩小，搜索区间向左折半、
    // 退出循环时，存在 speed = left = right 恰好满足 checkAvailable(M, nums,
    // speed)
    if (checkAvailable(M, nums, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  // 退出循环时，left = right 是恰好可以完成供餐的最小速度
  cout << left << endl;

  return 0;
}
