// https://og7kl7g6h8.feishu.cn/docx/TFMqdo6ipoL5OixddjhcsCVRnZd
#include <iostream>
#include <string>

void greedy(const std::string &S, const std::string &L) {
  int si = 0;
  int li = 0;
  while (si < S.length() && li < L.length()) {
    if (S[si] == L[li]) {
      si++;
      li++;
    } else {
      li++;
    }
  }

  std::cout << ((si == S.length()) ? (li - 1) : -1) << std::endl;
}

int main() {
  std::string S, L;
  std::cin >> S >> L;

  greedy(S, L);

  return 0;
}
