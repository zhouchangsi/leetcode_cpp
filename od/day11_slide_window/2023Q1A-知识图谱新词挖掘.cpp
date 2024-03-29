/**
 * https://og7kl7g6h8.feishu.cn/docx/VTSOdizRsoJ23QxOHSHcDs6Enkd
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string content;
  string word;
  getline(cin, content);
  getline(cin, word);

  int k = word.size();
  unordered_map<char, int> cntWord;
  for (char c : word) {
    cntWord[c]++;
  }

  unordered_map<char, int> cntWindows;
  int ans = 0;

  for (int right = 0; right < k; right++) {
    char rightCh = content[right];
    cntWindows[rightCh]++;
  }

  if (cntWindows == cntWord) {
    ans++;
  }

  for (int right = k; right < content.size(); right++) {
    char rightCh = content[right];
    cntWindows[rightCh]++;

    int left = right - k;
    char leftCh = content[left];
    cntWindows[leftCh]--;
    if (cntWindows[leftCh] == 0) {
      cntWindows.erase(leftCh);
    }

    if (cntWindows == cntWord) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
