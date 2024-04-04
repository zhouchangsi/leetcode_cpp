// https://og7kl7g6h8.feishu.cn/docx/AlXmdfpQzoOlQvxrhPxch6MKnRh
#include <bits/stdc++.h>
using namespace std;

// class TrieNode {
//  public:
//   bool is_end = false;
//   unordered_map<char, TrieNode*> children;
// };

// class Trie {
//  public:
//   TrieNode* root;
//   int size = 0;
//   Trie() { root = new TrieNode(); }
//   ~Trie() {
//     delete root;
//     root = nullptr;
//   }
//   void insert(const string& word) {
//     TrieNode* node = root;
//     for (char c : word) {
//       if (!node->children.count(c)) {
//         node->children[c] = new TrieNode();
//       }
//       node = node->children[c];
//     }
//     node->is_end = true;
//     size++;
//   }

//   const bool search(const string& word) const {
//     TrieNode* node = root;
//     for (char c : word) {
//       if (!node->children.count(c)) return false;
//       node = node->children[c];
//     }
//     return node->is_end;
//   }

//   const bool startsWith(const string& prefix) const {
//     TrieNode* node = root;
//     for (char c : prefix) {
//       if (!node->children.count(c)) return false;
//       node = node->children[c];
//     }
//     return true;
//   }

//   vector<string> words_with_prefix(string prefix) {
//     TrieNode* node = root;
//     for (char c : prefix) {
//       if (!node->children.count(c)) return {};
//       node = node->children[c];
//     }
//     // 此时node指向prefix的最后一个字符
//     vector<string> res;
//     dfs(node, prefix, res);
//     return res;
//   }

//   void dfs(TrieNode* node, string word, vector<string>& res) {
//     if (node->is_end) res.push_back(word);
//     for (auto [c, next] : node->children) {
//       dfs(next, word + c, res);
//     }
//   }
// };

// void solution(string s, string prefix) {
//   vector<string> words;
//   regex word_regex("(\\w+)");
//   for (auto it = sregex_iterator(s.begin(), s.end(), word_regex);  //
//        it != sregex_iterator();                                    //
//        it++                                                        //
//   ) {
//     words.push_back(it->str());
//   }

//   Trie trie;
//   for (string word : words) {
//     trie.insert(word);
//   }

//   vector<string> res = trie.words_with_prefix(prefix);

//   if (res.empty())
//     cout << prefix;
//   else
//     for (string word : res) cout << word << " ";
// }

void solution(string s, string prefix) {
  unordered_set<string> words;
  regex word_regex("(\\w+)");
  for (auto it = sregex_iterator(s.begin(), s.end(), word_regex);  //
       it != sregex_iterator();                                    //
       it++                                                        //
  ) {
    words.insert(it->str());
  }

  vector<string> res;
  for (auto word : words) {
    if (word.find(prefix) == 0) {
      res.push_back(word);
    }
  }
  // 字典序排序
  sort(res.begin(), res.end());

  if (res.empty())
    cout << prefix;
  else
    for (string word : res) cout << word << " ";
}

int main() {
  //   solution("I love you", "He");
  // solution(
  //     "The furthest distance in the world,Is not between life and death,But "
  //     "when I stand in front or you,Yet you don't know that I love you.",
  //     "f");

  string line;
  getline(cin, line);
  string prefix;
  getline(cin, prefix);
  solution(line, prefix);

  return 0;
}