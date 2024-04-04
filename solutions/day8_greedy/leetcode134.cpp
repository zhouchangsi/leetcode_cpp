/**
 * https://leetcode.cn/problems/gas-station/submissions/510091644/
 * https://r07na4yqwor.feishu.cn/docx/KJ0OduxXfoGwMcxUs00cBX4onyr
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         // 获取加油站的数量
        int n = gas.size();

        // 一开始，默认汽车储备的汽油数量为 0
        int remainGas = 0;

        // 需要统计一下，所有加油站的汽油总量能否支持汽车跑完所有的路程
        for( int start = 0 ; start < n ; start++ ){

            remainGas += gas[start] - cost[start];
        }

        // 如果发现加油站的汽油总量小于所有的路程需要消耗的汽油总量
        // 即汽车最终油箱汽油为负，那无论选择在哪出发，都不可能绕环路行驶一周
        if( remainGas < 0 ){

            return -1;
        }

        // 如果发现加油站的汽油总量大于或者等于所有的路程需要消耗的汽油总量
        // 那么可以绕环路行驶一周，接下来去寻找出发位置

        // 一开始，默认汽车此时储备的汽油数量为 0
        int currentGas = 0;

        // 一开始，默认汽车出发位置在索引为 0 的加油站
        int start = 0;

        // start_ans 表示最终选择的出发点，默认为 0
        int start_ans = 0;

        // 依次遍历每个加油站，在遍历的过程中，会执行一些【跳跃操作】
        while ( start < n ){

            // 汽车在 start 号加油站加了 gas[start]
            // 开到 start + 1 号加油站消耗了 cost[start] 的汽油
            currentGas += gas[start] - cost[start];
            
            // 如果发现油箱里面的汽油是非负数
            // 即汽车可以开到  j 号加油站，j >= start + 1，那么就让汽车继续尝试往前开
            // 寻找出从 start 号加油站出发到最远的加油站的位置 j ，在这期间汽车是会从中间的加油站加油的
            if( currentGas >= 0){

                start++;

            // 如果发现油箱里面的汽油是负数
            // 意味着汽车无法从 start 号加油站开到 j 号加油站，同时也意味着无法从 start + 1 号加油站开到 j 号加油站
            // 那么就直接尝试让汽车从 j 号加油站开始重新出发 
            }else{
                
                // 重新初始化汽车油箱油量
                currentGas = 0;

                // 最终选择的出发点为 j 号加油站
                start_ans = start + 1;

                // 开始出发
                start++;
            }
        }

        // 最终找到了合适的出发点
        return start_ans;
    }
};