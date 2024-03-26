/**
 * https://og7kl7g6h8.feishu.cn/docx/PoERdvGHNo9XUixVa89cLJJvnYd
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, vector<int>> nodes;
vector<int> vals;

int ans = -INFINITY;

void dfs(int cur_node, int pre_max) {
    int cur_max = (pre_max < 0) ? vals[cur_node] : vals[cur_node] + pre_max;
    ans = max(ans, cur_max);

    if (nodes.find(cur_node) == nodes.end()) {
        return;
    } else {
        for (int nxt_node : nodes[cur_node]) {
            dfs(nxt_node, cur_max);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vals.resize(n);

    for (int i = 0; i < n; ++i) {
        int idx, parent, val;
        cin >> idx >> parent >> val;
        nodes[parent].push_back(idx);
        vals[idx] = val;
    }

    int root = nodes[-1][0];
    dfs(root, 0);
    cout << ans << endl;
    return 0;
}
