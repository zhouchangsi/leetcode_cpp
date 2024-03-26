#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
//   long n = 12341;
  long n = 42234;
  // cin>>n;
  string s = to_string(n);
  int last[10];
  for (int i = 0; i < s.size(); i++) last[s[i] - '0'] = i;
  bool seen[10] = {false};
  stack<char> sk;
  for (int i = 0; i < s.size(); i++) {
    if (seen[s[i] - '0']) continue;
    while (!sk.empty() && s[i] > sk.top() && i < last[sk.top() - '0']) {
      seen[sk.top() - '0'] = false;
      sk.pop();
    }
    sk.push(s[i]);
    seen[s[i] - '0'] = true;
  }
  string t;
  while (!sk.empty()) {
    t = sk.top() + t;
    sk.pop();
  }
  cout << stol(t) << endl;
  return 0;
}