/**
 * https://leetcode.cn/problems/design-parking-system/description/
 * https://ahym1n4sq5.feishu.cn/docx/ZsjhdL9wboEXltx2fY4cJYMNnFb
 */
class ParkingSystem
{
public:
  ParkingSystem(int big, int medium, int small)
  {
    this->big = big;
    this->medium = medium;
    this->small = small;
  }

  bool addCar(int carType)
  {
    if (carType == 1) {
      if (big > 0) {
        big--;
        return true;
      }
    } else if (carType == 2) {
      if (medium > 0) {
        medium--;
        return true;
      }
    } else if (carType == 3) {
      if (small > 0) {
        small--;
        return true;
      }
    }
    return false;
  }

private:
  int big;
  int medium;
  int small;
};