#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 明明生成了N 个 1 至 500
 * 之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
 */
set<int> random_number_of_mingming(vector<int>& numbers) {
  set<int> num_set;
  for (int i = 0; i < numbers.size(); i++) {
    num_set.insert(numbers[i]);
  }
  // for (int num : num_set) {
  //   cout << num << endl;
  // }
  return num_set;
}

/**
 * 【哈希集合】2023C-英文输入法
 * https://og7kl7g6h8.feishu.cn/docx/AlXmdfpQzoOlQvxrhPxch6MKnRh
 */
class Solution {
 public:
  set<string> build_words_set(vector<string>& words) {
    set<string> word_set;
    for (string word : words) {
      word_set.insert(word);
    }
  }
  set<string> word_set;
  vector<string> english_input_method(string prefix) {
    vector<string> result;
    for (string word : word_set) {
      if (word.substr(0, prefix.length()) == prefix) {
        result.push_back(word);
      }
    }
    return result;
  }
};

/**
 * 【哈希集合】2023Q1A-寻找密码
 * https://og7kl7g6h8.feishu.cn/docx/Ha5ed2grHohySPxQanSc52rCnJb
 */
class Solution {
 public:
  set<string> password_set;
  bool is_valid_password(string password) {
    for (int i = 0; i < password.size(); i++) {
      string prefix = password.substr(0, i);
      if (password_set.find(prefix) != password_set.end()) {
        false;
      }
    }
    return true;
  }

  string find_max_password() {
    string max_password;
    for (string password : password_set) {
      if (is_valid_password(password)) {
        if (max_password.empty() || password.size() > max_password.size()) {
          max_password = password;
        }
      }
    }
    return max_password;
  }
};