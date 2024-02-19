#include <set>
#include <vector>
using namespace std;

/**
 * @brief 明明生成了N 个 1 至 500
 * 之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
 */
set<int>
random_number_of_mingming(vector<int>& numbers)
{
  set<int> num_set;
  for (int i = 0; i < numbers.size(); i++) {
    num_set.insert(numbers[i]);
  }
  // for (int num : num_set) {
  //   cout << num << endl;
  // }
  return num_set;
}