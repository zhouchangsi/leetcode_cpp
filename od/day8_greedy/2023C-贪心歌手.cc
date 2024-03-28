// https://og7kl7g6h8.feishu.cn/docx/E3c7dZcwJo0xPCx8485chQn0nBf
#include <bits/stdc++.h>
using namespace std;

struct City {
  int money, descend;
  bool operator<(const City& right) const {
    if (money == right.money) return descend > right.descend;
    // priority_queue 默认是大顶堆, 默认使用 < 运算符, 即less<City>
    // less<City> 会使得堆顶元素是最大的
    return money < right.money;
  }
};

int main() {
  // int day_limit = 10, city_num = 3;
  // string line = "1 1 2 3";
  // istringstream iss(line);
  // while (iss >> line) day_limit -= stoi(line);
  // vector<City> cities = {{120, 20}, {90, 10}, {100, 20}};

  int day_limit, city_num;
  cin >> day_limit >> city_num;
  int time_num = city_num + 1, time;
  while (time_num--) {
    cin >> time;
    day_limit -= time;
  }
  vector<City> cities;
  while (city_num--) {
    int money, descend;
    cin >> money >> descend;
    cities.push_back({money, descend});
  }

  priority_queue<City> pq(cities.begin(), cities.end());

  int sum = 0;
  while (day_limit--) {
    if (pq.empty()) break;
    City c = pq.top();
    pq.pop();
    sum += c.money;
    c.money -= c.descend;
    if (c.money > 0) {
      pq.push(c);
    }
  }

  cout << sum << endl;

  return 0;
}