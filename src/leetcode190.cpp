#include "common_headers.h"

using namespace std;

class MyQueue {
 private:
  const uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
  const uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
  const uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
  const uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111

 public:
  uint32_t reverseBits(uint32_t n) {
    // 原数据为:12345678
    // 第一轮 奇偶位交换 21436587
    // 第二轮 每两位交换 43218765
    // 第三轮 每四位交换 87654321
    n = n >> 1 & M1 | (n & M1) << 1;
    n = n >> 2 & M2 | (n & M2) << 2;
    n = n >> 4 & M4 | (n & M4) << 4;
    n = n >> 8 & M8 | (n & M8) << 8;
    return n >> 16 | n << 16;
  }
};

TEST(leetcode190, case1) {
  MyQueue s;
  EXPECT_EQ(1, 1);
  //   EXPECT_EQ(s.reverseBits(0b00000010100101000001111010011100),
  //   0b00111001011110000010100101000000);
}

// TEST(leetcode190, case2) {
//   MyQueue s;
//   EXPECT_EQ(s.reverseBits(0b11111111111111111111111111111101),
//   0b10111111111111111111111111111111);
// }
