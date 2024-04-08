/**
 * https://leetcode.cn/problems/valid-perfect-square/description/
 * https://r07na4yqwor.feishu.cn/docx/EHP5dMdAVo5GkKxET3lc2DTFnch
 */

#include "../leetcode.h"

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            long square = (long)mid * mid;
            if (square < num)
            {
                left = mid + 1;
            }
            else if (square > num)
            {
                right = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = num;

        // 在区间 [left , right] 这个左闭右闭的区间里面去查找
        // 查找什么呢？
        // 查找是否存在一个数 a，使得 a * a = num

        // 在 while 循环里面，left 不断的向右移动，而 right 不断的向左移动
        // 当 [ left , right ] 这个区间不存在元素的时候，才跳出 while 循环，也就是当 left > right 时跳出循环
        // 即当 left = right + 1 时，搜索区间没有元素了
        // 由于 left 和 right 相遇的时候指向同一个元素，这个元素是存在于 [ left , right] 区间，这个区间就一个元素
        // 所以此时 while 循环的判断可以使用等号
        while (left <= right)
        {

            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 判断中间元素的平方与 num 的大小
            // 如果 mid * mid < num

            // mid * mid 的数值有可能超过 int 类型的最大数
            // 使用 long
            long square = (long)mid * mid;

            // 中间元素的平方小于了目标值 num
            // 数组为 [ 0 , n ]
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ left , mid ] 这个区间中的所有元素的平方都小于目标值 num
            // 因此，缩小查找区间为 [ mid + 1 , right]
            if (square < num)
            {
                // 也就是说缩小之后的区间最左侧位置为 mid + 1
                left = mid + 1;

                // 中间元素的平方大于了目标值 num
                // 数组为 [ 0 , n ]
                // 1、数组为有序数组，比如为递增数组
                // 2、数组中不存在重复元素
                // 由于该数组存在以上两个特点，所以 [ mid , right ] 这个区间中的所有元素的平方都大于目标值 num
                // 因此，缩小查找区间为 [ left , mid - 1]
            }
            else if (square > num)
            {
                // 也就是说缩小之后的区间最右侧位置为 mid - 1
                right = mid - 1;

                // 中间元素的平方等于了目标值 num
            }
            else if (square == num)
            {
                // 直接返回结果即可
                return true;
            }
        }

        // 查找完区间中的所有元素都没有找到，返回 false
        return false;
    }
};