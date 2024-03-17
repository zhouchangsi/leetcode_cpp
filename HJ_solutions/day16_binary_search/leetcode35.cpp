
/**
 * https://leetcode.cn/problems/search-insert-position/description/
 * https://r07na4yqwor.feishu.cn/docx/LNOBd8YJdoeamyx6piJc6lafn7f
*/
#include "../leetcode/leetcode.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = nums.size() - 1;

        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 在区间 nums[left..right] 里查找第 1 个大于等于 target 的元素的下标
        while(left <= right) {

            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 中间的元素和目标值 target 相等，直接返回下标即可，不需要插入
            if(nums[mid] == target) {
                // 直接返回下标即可
                return mid;
            
            // 中间的元素大于了目标值 target
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ mid , right ] 这个区间中的所有元素都大于目标值 target
            // 因此，缩小查找区间为 [ left , mid - 1]
            } else if(nums[mid] > target) {
                // 也就是说缩小之后的区间最右侧位置为 mid - 1
                right = mid - 1;
            
            // 中间的元素小于了目标值 target
            // 1、数组为有序数组，比如为递增数组
            // 2、数组中不存在重复元素
            // 由于该数组存在以上两个特点，所以 [ left , mid ] 这个区间中的所有元素都小于目标值 target
            // 因此，缩小查找区间为 [ mid + 1 , right]
            } else if(nums[mid] < target){
                // 也就是说缩小之后的区间最左侧位置为 mid + 1
                left = mid + 1;
            }
        }
        
        // 执行到这里，说明退出了 while 循环，在 nums 里面没有找到和目标值 target 相同的元素，需要将 target 插入到 nums 中
        // 在上面 while 循环每次的操作中，都会使得 [ left , right ] 的这个区间中的元素减少，直到 left = right + 1 出现区间不存在元素位置
        // 在出现这种情况之前，也就是 while 循环操作的最后一次时，left = right，那么此时计算的 mid = left = right
        // 此时 nums[mid] 左边的数全部小于目标值 target ，nums[mid] 右边的数全部大于目标值 target
        // 1、如果 nums[mid] 大于 target，那么接下来 right 会向左移动，即 right = left - 1，此时搜索区间不存在
        // 那么说明 target 应该插入到 nums[mid] 的前一个位置，也就是顶替了 nums[mid] 的位置，nums[mid] 后面所有元素都向后移动
        // 而此时 left 指向的就是 nums[mid] 这个元素，所以 left 就是插入的位置
        // 2、如果 nums[mid] 小于 target，那么接下来 left 会向右移动，即 left = right + 1，此时搜索区间不存在
        // 那么说明 target 应该插入到 nums[mid] 的后一个位置，而 left 向后移动了一次，这个位置就是插入位置
        return left;

    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};