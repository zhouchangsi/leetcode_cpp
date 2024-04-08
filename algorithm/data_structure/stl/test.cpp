#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <string>

using namespace std;

int main() {
  // 自定义比较函数
  {
    // 1. 使用function
    set<string, function<bool(const string&, const string&)>> s1(
        [](auto a, auto b) { return a.size() > b.size(); });

    // 2. 使用decltype
    auto cmp = [](const auto& a, const auto& b) { return a.size() > b.size(); };
    set<string, decltype(cmp)> s2(cmp);

    s1.insert("a");
    s1.insert("ab");
    s1.insert("abc");
    // s1 = {"abc", "ab", "a"}
  }

  // 在函数内部定义递归函数
  {
    function<int(int)> factorial = [&](int n) {
      if (n == 0 || n == 1) {
        return 1;
      } else {
        return n * factorial(n - 1);  // 递归调用
      }
    };
  }

  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = {1, 2, 3, 4, 5};

  isalpha('a');  // true
  isdigit('1');  // true
  isalnum('a');  // true
  islower('a');  // true
  isupper('A');  // true
  tolower('A');  // 'a'
  stoi("123");   // 123

  return 0;
}
