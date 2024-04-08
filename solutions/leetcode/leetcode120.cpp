/**
 * https://leetcode.cn/problems/triangle/description/
 * https://r07na4yqwor.feishu.cn/docx/FaVfd5yQao6NODx6TQ1cj6ISnSd
*/
#include "../leetcode.h"
    
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // triangle 是个二维数组
        // 先获取 triangle 的层数，即一维数组的个数
        int n  = triangle.size();

        // 设置一个一维数组，动态的更新每一层中当前节点对应的最短路径
        vector<int> dp( n + 1 );

        // 从最后一层开始计算节点的最短路径，直到顶层 0 层为止
        for (int i = n - 1 ; i >= 0 ; i-- ){
            // dp 中存储的是前 i 个位置存储的是到达第 i 层各个节点的最小路径和
            // 从每一层的第 0 个位置开始
            for(int j = 0 ; j <= i ; j++){
                // dp[j] 表示第 i 层中第 j 个节点的最小路径和
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }

        // 返回结果
        return dp[0];
    }
};