/**
 * https://og7kl7g6h8.feishu.cn/docx/VjK6dUSjpo77mVxkd3XcB7ZfnBh
 */
#include <iostream>
#include <climits>
#include <sstream>
#include <vector>

using namespace std;

int solve(string line) {
  istringstream iss(line);
  string person;
  vector<string> team;
  while (getline(iss, person, ',')) {
    team.push_back(person);
  }

  vector<int> cnt(5, 0);
  for (const string& person : team) {
    for (int i = 0; i < person.length(); i++) {
      if (person[i] == '1') {
        cnt[i]++;
      }
    }
  }

  int min_count = INT_MAX;
  for (int count : cnt) {
    min_count = min(min_count, count);
  }

  return min_count;
}

int main() {
//   cout << solve("11001,11101") << endl;
//   cout << solve("11101,10111") << endl;

  string line;
  getline(cin, line);
  cout << solve(line) << endl;
}
