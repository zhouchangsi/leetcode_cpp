// https://og7kl7g6h8.feishu.cn/docx/QdMpdNfjHo98k6xfePHc8mYYnHg
#include <bits/stdc++.h>
using namespace std;

struct Task {
  int deadline;
  int reward;
  bool operator<(const Task &other) const { return reward < other.reward; }
};

void greedy(int deadline, vector<Task> tasks) {
  unordered_map<int, vector<Task>> task_map;

  for (auto task : tasks) {
    int t = min(task.deadline, deadline);
    task_map[t].push_back(task);
  }

  int ans = 0;
  priority_queue<Task> pq;

  for (int t = deadline; t > 0; t--) {
    auto task_list = task_map[t];
    for (auto task : task_list) pq.push(task);

    if (pq.empty()) continue;
    auto max_reward_task = pq.top();
    pq.pop();
    ans += max_reward_task.reward;
  }

  cout << ans << endl;
}

int main() {
  // greedy(3, {{1, 3}, {2, 2}, {3, 1}, {3, 4}, {4, 5}});
  int deadline, n;
  cin >> deadline >> n;
  vector<Task> tasks(n);
  for (int i = 0; i < n; i++) {
    cin >> tasks[i].deadline >> tasks[i].reward;
  }
  greedy(deadline, tasks);
}