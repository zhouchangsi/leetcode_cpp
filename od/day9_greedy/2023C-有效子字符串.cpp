#include <iostream>
#include <string>

int main() {
  std::string S, L;
  std::cin >> S >> L;

  int ns = S.length();
  int nl = L.length();
  int ps = 0;
  int pl = 0;

  while (ps < ns && pl < nl) {
    if (S[ps] == L[pl]) {
      ps++;
      pl++;
    } else {
      pl++;
    }
  }

  std::cout << ((ps == ns) ? (pl - 1) : -1) << std::endl;

  return 0;
}
