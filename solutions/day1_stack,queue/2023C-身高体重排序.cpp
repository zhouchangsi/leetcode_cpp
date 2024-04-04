/**
 * https://og7kl7g6h8.feishu.cn/docx/ZTITdCzvaoNkHxxBbmocvVy5nAd
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
  int height;
  int weight;
  int index;
};

void solution(vector<Student>& student) {
  sort(student.begin(), student.end(), [](const Student& a, const Student& b) {
    if (a.height == b.height) {
      if (a.weight == b.weight) {
        return a.index < b.index;
      }
      return a.weight < b.weight;
    }
    return a.height < b.height;
  });

  for (const auto& s : student) cout << s.index;
}

int main() {
  //   vector<Student> student = {
  //       {100, 40, 1}, {100, 30, 2}, {120, 60, 3}, {130, 50, 4}};
  //   solution(student);

  int n;
  cin >> n;
  vector<Student> student(n);
  for (int i = 0; i < n; ++i) {
    cin >> student[i].height;
  }
  for (int i = 0; i < n; ++i) {
    cin >> student[i].weight;
    student[i].index = i + 1;
  }
  solution(student);

  return 0;
}
