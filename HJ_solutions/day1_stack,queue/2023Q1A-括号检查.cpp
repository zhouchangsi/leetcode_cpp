/**
 * https://og7kl7g6h8.feishu.cn/docx/Lb02dypAmoNxu8xbBQncrBnkn0e
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    // 初始化用于判断异常的变量isError，初始化为False表示没有异常
    bool isError = false;
    // 初始化答案变量ans和记录当前深度的变量cur_depth
    int ans = 0;
    int cur_depth = 0;
    // 构建三种括号的两两配对关系
    vector<pair<char, char>> pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    // 若字符串长度为奇数，必定无法配对，isError设置为True
    if (s.length() % 2 == 1) {
        isError = true;
    } else {
        // 使用列表vector初始化一个空栈
        vector<char> stack;
        // 一次遍历字符串s中的每一个字符ch
        for (char ch : s) {
            // 若ch为某种左括号
            if (ch == '(' || ch == '{' || ch == '[') {
                // 则将ch加入栈顶，同时括号深度+1，更新最大括号深度
                stack.push_back(ch);
                cur_depth++;
                ans = max(ans, cur_depth);
            } else {
                // 若此时栈为空
                if (stack.empty()) {
                    // 该右括号无法与左括号配对，出现异常，isError设置为True，同时退出循环
                    isError = true;
                    break;
                }
                // 若栈不为空，则弹出栈顶字符，同时括号深度-1
                char ch_stack_top = stack.back();
                stack.pop_back();
                cur_depth--;
                // 若栈顶左括号字符ch_stack_top和当前右括号字符ch不配对，
                // 出现异常，isError设置为True，同时退出循环
                bool isPair = false;
                for (auto pair : pairs) {
                    if (pair.first == ch_stack_top && pair.second == ch) {
                        isPair = true;
                        break;
                    }
                }
                if (!isPair) {
                    isError = true;
                    break;
                }
            }
        }
        // 经过一次遍历后，若仍存在元素，说明存在括号未配对，出现异常，isError设置为True
        if (!stack.empty()) {
            isError = true;
        }
    }

    // 如果isError标志为True，说明前面某一步出现异常，输出0，否则输出最大深度ans
    cout << (isError ? 0 : ans) << endl;
    return 0;
}
