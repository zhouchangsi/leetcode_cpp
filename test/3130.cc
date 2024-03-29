#include <bits/stdc++.h>
using namespace std;

struct Task {
  int deadline;
  int reward;
};

void greedy(int deadline, vector<Task> tasks) {
  // alive_task means the task that we are currently working on
  vector<Task> alive(tasks.begin(), tasks.end());

  unordered_map<int, vector<Task>> task_map;
  for (auto task : tasks) {
    task_map[task.deadline].push_back(task);
  }

  int max_reward = 0;
  while (deadline) {
    sort(alive.begin(), alive.end(),
         [](Task a, Task b) { return a.reward < b.reward; });

    auto max_reward_task = alive.back();
    alive.pop_back();
    max_reward += max_reward_task.reward;

    auto same_deadline_tasks = task_map[deadline];
  }
}

int main() { greedy(5, {{1, 3}, {2, 2}, {3, 1}, {3, 4}, {4, 5}}); }