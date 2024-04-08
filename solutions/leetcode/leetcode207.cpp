/**
 * https://leetcode.cn/problems/course-schedule/description/
 * https://og7kl7g6h8.feishu.cn/docx/SJMedkcxrolGmkx7IsScvm6qn5d
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in_degree = vector<int>(numCourses, 0);
    unordered_map<int, vector<int>> connection;
    for (auto& prerequisite : prerequisites) {
      int cur = prerequisite[0], pre = prerequisite[1];
      in_degree[cur]++;
      connection[pre].emplace_back(cur);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) q.emplace(i);
    }
    int select_count = 0;
    while (!q.empty()) {
      int cur_course = q.front();
      q.pop();
      select_count++;

      for (auto& next_course : connection[cur_course]) {
        in_degree[next_course]--;
        if (in_degree[next_course] == 0) {
          q.emplace(next_course);
        }
      }
    }
    return select_count == numCourses;
  }
};