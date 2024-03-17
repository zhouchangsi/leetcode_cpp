#include <functional>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  set<string, function<bool(const string&, const string&)>> s(
      [](auto a, auto b) { return a.size() > b.size(); });

  s.insert("a");
  s.insert("ab");
  s.insert("abc");
  // s = {"abc", "ab", "a"}

  // 在外部函数内部定义递归函数
  function<int(int)> factorial = [&](int n) {
    if (n == 0 || n == 1) {
      return 1;
    } else {
      return n * factorial(n - 1);  // 递归调用
    }
  };

  

  cout << factorial(5) << endl;

  return 0;
}
