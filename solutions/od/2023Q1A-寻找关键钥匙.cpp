// https://og7kl7g6h8.feishu.cn/docx/FVRvddnxqoHd1zxYUy4ccSrqnfc
#include <bits/stdc++.h>
using namespace std;

void hash_map(string pwd, string line) {
  set<char> pwd_set(pwd.begin(), pwd.end());

  set<char> box_set;
  string box;
  istringstream iss(line);
  int index = 1;
  while (iss >> box) {
    for (auto ch : box) {
      if (isalpha(ch)) {
        box_set.insert(tolower(ch));
      }
    }
    if (pwd_set == box_set) {
      cout << index << '\n';
      return;
    }
    index++;
    box_set.clear();
  }
  cout << -1 << '\n';
}

int main() {
  //   hash_map("abc", "s,sdf134 A2c4b");
  //   hash_map("abc", "s,sdf134 A2c4bd 523[]");

  string pwd, line;
  getline(cin, pwd);
  getline(cin, line);
  hash_map(pwd, line);

  return 0;
}