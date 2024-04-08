/**
 * https://leetcode.cn/problems/keys-and-rooms/
 * https://og7kl7g6h8.feishu.cn/docx/M9tadV4OmoY2l5xLBBzcf8hun4m
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    int count = 0;
    void dfs(vector<vector<int>>& rooms, int id) {
        if (visited.count(id)) {
            return;
        }
        count++;
        visited.insert(id);
        for (auto room_key : rooms[id]) {
            dfs(rooms, room_key);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        return count == rooms.size();
    }
};