// https://leetcode.cn/problems/walking-robot-simulation/description/
// https://r07na4yqwor.feishu.cn/docx/Bj33du5FVoLcZaxuj5sc4qUEnwd
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0;
    int y = 0;
    int dir = 0;
    int max_ans = 0;
    void turn_left() { dir = (dir + 3) % 4; }
    void turn_right() { dir = (dir + 1) % 4; }
    void move(int distance, unordered_map<int, unordered_set<int>>& os) {
        while (distance--) {
            auto [dx, dy] = dirs[dir];
            int nx = x + dx, ny = y + dy;
            if (os.count(nx) && os[nx].count(ny)) {
                break;
            }
            x = nx;
            y = ny;
            max_ans = max(max_ans, x * x + y * y);
        }
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> os;
        for (auto& o : obstacles) {
            os[o[0]].insert(o[1]);
        }

        for (auto c : commands) {
            if (c == -1) {
                turn_right();
            } else if (c == -2) {
                turn_left();
            } else {
                move(c, os);
            }
        }

        return max_ans;
    }
};