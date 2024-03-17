/**
 * https://og7kl7g6h8.feishu.cn/docx/P136doyMRo83e4xuMJVcANX3n0f
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 该函数用于检查：当选择两树最小间距为 interval 时，能否种下 N 棵树
bool checkAvailable(int interval, vector<int>& trees, int N) {
    // 第一个位置肯定种下，因此种下的数目 num 初始化为 1
    int num = 1;
    // 初始化变量 preTree，用于记录上一棵树的位置
    int preTree = trees[0];
    // 从索引为 1 的树开始，遍历所有 trees
    for (int i = 1; i < trees.size(); i++) {
        int curTree = trees[i];
        // 如果当前树 curTree 和上一棵树 preTree 的距离超过传入的间距 interval，
        // 那么可以在 curTree 的位置种下一棵树，种下的数目 num + 1
        // 同时 preTree 需要更新为 curTree，即对于下一棵树而言，当前 curTree 是其上一棵树
        if (curTree - preTree >= interval) {
            preTree = curTree;
            num++;
            // 如果在当前 interval 的条件下，当前种下数目 num 可以等于要求种植数量 N，
            // 那么返回 true，表示该 interval 是一个合适的间隔距离。
            if (num == N) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // M 个坑
    int M;
    cin >> M;
    // M 个坑位具体位置
    vector<int> trees(M);
    for (int i = 0; i < M; i++) {
        cin >> trees[i];
    }
    // 种 N 棵树
    int N;
    cin >> N;

    // 对 trees 数组进行排序，方便统计相邻坑位距离
    sort(trees.begin(), trees.end());

    int left = 1, right = trees[trees.size() - 1] - trees[0] + 1;

    // 左闭右开区间，退出循环时存在 left = right = mid
    // 循环不变量为 left < right
    while (left < right) {
        // 计算 left 和 right 的平均值 mid
        int mid = (left + right) / 2;
        // 当间隔取 mid 时，可以种入 N 棵树
        // 说明当前间隔 mid 太小，left 右移
        // 退出循环时，left 恰好不满足 if 条件语句
        // 即存在 checkAvailable(left, trees, N) 为 false
        // left 是该式子成立的第一个整数，故 left - 1 是为答案
        if (checkAvailable(mid, trees, N)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // interval = left - 1 是使得 checkAvailable(interval, trees, N) 满足的最大整数
    cout << left - 1 << endl;

    return 0;
}
