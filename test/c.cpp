#include <bits/stdc++.h>
using namespace std;

class FileCache {
 public:
  FileCache(int capacity) : capacity(capacity) {}

  string get(string key) {
    if (cache_map.find(key) == cache_map.end()) return "NONE";

    // update file info
    cache_map[key].count++;
    cache_map[key].time = current_time++;

    return key;
  }

  void put(string key, int size) {
    if (cache_map.find(key) != cache_map.end()) return;
    if (size > capacity) return;
    while (current_size() + size > capacity) delete_file();

    // new file
    cache_map[key] = {key, size, 0, current_time++};
  }

  int capacity;
  int current_time = 0;

  struct File {
    string name;
    int size;
    int count;
    int time;
  };

  map<string, File> cache_map;
  int current_size() {
    return accumulate(cache_map.begin(), cache_map.end(), 0,
                      [&](int sum, const pair<string, File>& kv) {
                        return sum + kv.second.size;
                      });
  }

  void delete_file() {
    auto it =
        min_element(cache_map.begin(), cache_map.end(), [](auto a, auto b) {
          return a.second.count == b.second.count
                     ? a.second.time < b.second.time
                     : a.second.count < b.second.count;
        });
    cache_map.erase(it);
  }
};

int main() {
  int m = 50, n = 6;
  cin >> m;
  cin.ignore();
  cin >> n;
  cin.ignore();
  FileCache fc(m);

  vector<string> lines(n);
  //   vector<string> lines = {"put a 10", "put b 20", "get a",
  //                           "get a",    "get b",    "put c 30"};
  string line;
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    lines[i] = line;
  }

  for (auto line : lines) {
    stringstream ss(line);
    string cmd, key;
    int size;
    ss >> cmd;
    if (cmd == "put") {
      ss >> key >> size;
      fc.put(key, size);
    } else {
      ss >> key;
      fc.get(key);
    }
  }

  if (fc.cache_map.size() == 0) {
    cout << "NONE";
  } else {
    for (auto it = fc.cache_map.begin(); it != fc.cache_map.end(); it++) {
      cout << it->first;
      if (next(it) != fc.cache_map.end()) cout << ",";
    }
  }

  return 0;
}