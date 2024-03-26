/**
 * https://og7kl7g6h8.feishu.cn/docx/OAMMdvCuDocxiZxW5vvcJztgnAe
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;

bool check(const unordered_map<char, int> &cntWin, const unordered_map<char, int> &cntSub) {
    for (const auto &entry : cntSub) {
        if (cntWin.find(entry.first) == cntWin.end() || cntWin.at(entry.first) < entry.second) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    int num = s.length() / 4;

    unordered_map<char, int> count;
    for (char ch : s) {
        count[ch]++;
    }

    unordered_map<char, int> cntSub;
    for (const auto &entry : count) {
        if (entry.second > num) {
            cntSub[entry.first] = entry.second - num;
        }
    }

    if (cntSub.empty()) {
        cout << 0 << endl;
    } else {
        unordered_map<char, int> cntWin;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            cntWin[ch]++;

            while (check(cntWin, cntSub)) {
                ans = min(ans, right - left + 1);
                char leftChar = s[left];
                cntWin[leftChar]--;
                left++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
