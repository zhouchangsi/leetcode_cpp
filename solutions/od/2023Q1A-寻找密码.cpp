// https://og7kl7g6h8.feishu.cn/docx/Ha5ed2grHohySPxQanSc52rCnJb

#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

void solution(vector<string> passwords) {
  sort(passwords.begin(), passwords.end());
  unordered_set<string> valid_set;
  valid_set.insert("");  // 为了让单个字符的密码在减去字符后也能被判断为有效

  string ans;

  for (const string& p : passwords) {
    // 如果password去掉最后一位的结果password[:-1]，位于valid_set哈希集合中
    // 说明当前的password是一个有效密码，将其加入valid_set，同时更新ans
    string password_without_last = p.substr(0, p.length() - 1);
    if (valid_set.count(password_without_last)) {
      valid_set.insert(p);

      if (p.length() > ans.length() ||  // 如果当前password长度大于ans长度
          (p.length() == ans.length() && p > ans)  // 或者长度相等但字典序更大
      ) {
        ans = p;
      }
    }
  }

  cout << ans;
}

int main() {
  std::vector<std::string> passwords;
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);
  std::string password;
  while (iss >> password) {
    passwords.push_back(password);
  }
  solution(passwords);

  return 0;
}
