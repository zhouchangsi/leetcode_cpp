#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  vector<string> restoreIpAddresses(string s) {
    dfs(s, 0, 0);
    return ans;
  }

  string ip_seg[4];
  string get_ip() {
    return ip_seg[0] + "." + ip_seg[1] + "." + ip_seg[2] + "." + ip_seg[3];
  }
  vector<string> ans;

  void dfs(string s, int seg_start, int seg_id) {
    if (seg_start == s.size()) {
      ans.push_back(get_ip());
    } else {
      return;
    }

    if (s.at(seg_start) == '0') {
      ip_seg[seg_id] = "0";
      dfs(s, seg_start + 1, seg_id + 1);
    }

    int addr = 0;
    for (int seg_end = seg_start; seg_end < s.length(); ++seg_end) {
      addr = 10 * addr + static_cast<int>(s[seg_end]);
      if (addr > 0 && addr <= 0xFF) {
        ip_seg[seg_end] = addr;

      } else {
        break;
      }
    }
  }
};

TEST(leetcode93, case1) {
  MyQueue solution;
  string s = "25525511135";
  vector<string> expect = {"255.255.11.135", "255.255.111.35"};
  EXPECT_EQ(solution.restoreIpAddresses(s), expect);
}

TEST(leetcode93, case2) {
  MyQueue solution;
  string s = "25525511135";
  vector<string> expect = {};
  EXPECT_EQ(solution.restoreIpAddresses(s), expect);
}
