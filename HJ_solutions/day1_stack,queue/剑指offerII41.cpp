/**
 * https://ahym1n4sq5.feishu.cn/docx/H8XUdRtteoiLlexU3qzcnDlEnze
*/
#include <queue>
using namespace std;

class MovingAverage
{
public:
  MovingAverage(int size)
  {
    this->size = size;
    this->sum = 0;
  }

  double next(int val)
  {
    if (slide_window.size() == size) {
      sum -= slide_window.front();
      slide_window.pop();
    }
    slide_window.push(val);
    sum += val;
    return sum / slide_window.size();
  }

private:
  int size;
  queue<int> slide_window;
  double sum;
};