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
    if (q.size() == size) {
      sum -= q.front();
      q.pop();
    }
    q.push(val);
    sum += val;
    return sum / q.size();
  }

private:
  int size;
  queue<int> q;
  double sum;
};