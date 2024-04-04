#include <bits/stdc++.h>
using namespace std;

void solution(int k, int n, int m) {
  int count = 0;
  while (k) {
    if (k % m == n) count++;
    k /= m;
  }
  cout << count << endl;
}

int main() {
  // solution(10, 2, 4);
  // solution(10, 1, 3); //
  int k, n, m;
  cin >> k >> n >> m;
  solution(k, n, m);
}