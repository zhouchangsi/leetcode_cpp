// https://og7kl7g6h8.feishu.cn/docx/UL3OdNUTioOAMhxpsGmcEHTznQd
#include <bits/stdc++.h>
using namespace std;

void solution(string line) {
  stringstream ss(line);
  vector<string> words;
  string word;
  while (ss >> word) words.push_back(word);

  vector<string> sorted;
  for (string word : words) {
    sort(word.begin(), word.end());
    sorted.push_back(word);
  }

  map<string, int> count;
  for (string word : sorted) count[word]++;

  sort(sorted.begin(), sorted.end(), [&](const string &a, const string &b) {
    if (count[a] == count[b]) {
      if (a.length() == b.length()) return a < b;
      return a.length() < b.length();
    }
    return count[a] > count[b];
  });

  copy(sorted.begin(), sorted.end(), ostream_iterator<string>(cout, " "));
}

int main() {
  // solution("This is an apple");
  string line;
  getline(cin, line);
  solution(line);

  return 0;
}
