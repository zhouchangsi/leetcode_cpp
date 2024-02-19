#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string person;
    vector<string> team;
    while (getline(iss, person, ',')) {
        team.push_back(person);
    }

    unordered_map<int, int> cnt;

    for (const string& person : team) {
        for (int i = 0; i < person.length(); i++) {
            if (person[i] == '1') {
                cnt[i]++;
            }
        }
    }

    if (cnt.size() < 5) {
        cout << 0 << endl;
    } else {
        int minCount = INT_MAX;
        for (const auto& kv : cnt) {
            minCount = min(minCount, kv.second);
        }
        cout << minCount << endl;
    }

    return 0;
}
