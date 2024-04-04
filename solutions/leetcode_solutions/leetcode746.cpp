class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        int pre1 = cost[0];
        int pre0 = cost[1];
        int cur_cost = 0;
        for(int i = 2; i < n; i++) {
            cur_cost = min(pre0, pre1) + cost[i];
            pre1 = pre0;
            pre0 = cur_cost;
        }
        return min(pre0, pre1);
    }
};