// https://og7kl7g6h8.feishu.cn/docx/XWdhdEo8VoUO8ExGtREc4xjhnah

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> build_course_dic(const vector<string>& grades) {
  unordered_map<string, int> dic;
  for (const string& item : grades) {
    stringstream ss(item);
    string student_id, grade_str;
    getline(ss, student_id, ',');
    getline(ss, grade_str, ',');
    dic[student_id] = stoi(grade_str);
  }
  return dic;
}

void solve(string course1, string course2) {
  stringstream ss1(course1), ss2(course2);
  vector<string> lst1, lst2;
  string token;
  while (getline(ss1, token, ';')) {
    lst1.push_back(token);
  }
  while (getline(ss2, token, ';')) {
    lst2.push_back(token);
  }

  unordered_map<string, int> grade1 = build_course_dic(lst1);
  unordered_map<string, int> grade2 = build_course_dic(lst2);

  map<string, vector<string>> result;
  for (const auto& [student_id, _] : grade2) {
    if (grade1.find(student_id) != grade1.end()) {
      string class_id = student_id.substr(0, 5);
      result[class_id].push_back(student_id);
    }
  }

  if (result.empty()) {
    cout << "NULL" << endl;
    return;
  }

  for (auto& [class_id, students] : result) {
    sort(students.begin(), students.end(),
         [&](const string& a, const string& b) {
           int sum_a = grade1[a] + grade2[a];
           int sum_b = grade1[b] + grade2[b];
           if (sum_a == sum_b) {
             return a < b;
           }
           return sum_a > sum_b;
         });

    cout << class_id << endl;
    for (int i = 0; i < students.size(); i++) {
      cout << students[i];
      if (i != students.size() - 1) cout << ";";
    }
    cout << endl;
  }
}

int main() {
  //   solve("01202021,75;01201033,95;01202008,80;01203006,90;01203088,100",
  //         "01202008,70;01203088,85;01202111,80;01202021,75;01201100,88");

  string course1, course2;
  getline(cin, course1);
  getline(cin, course2);
  solve(course1, course2);

  return 0;
}
