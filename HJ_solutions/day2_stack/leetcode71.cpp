/**
 * https://leetcode-cn.com/problems/simplify-path/
 * https://ahym1n4sq5.feishu.cn/docx/IqcjdzdIaoMpncx0cFscBM7HnIc
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> s;
    string res, tmp;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
      if (tmp == "" || tmp == ".") continue;
      if (tmp == ".." && !s.empty())
        s.pop();
      else if (tmp != "..")
        s.push(tmp);
    }
    while (!s.empty()) {
      res = "/" + s.top() + res;
      s.pop();
    }
    return res.empty() ? "/" : res;
  }
};