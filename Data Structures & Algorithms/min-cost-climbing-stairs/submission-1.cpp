class Solution {
private:
    int dp(vector<int> &cost, int i, vector<int> &dpMat){
        if(i==cost.size()){
            return 0;
        }
        if(i>cost.size()){
            return 1e5;
        }
        if(dpMat[i]!=-1){
            return dpMat[i];
        }
        int ans = cost[i] + min(dp(cost, i+1, dpMat), dp(cost, i+2, dpMat));
        return dpMat[i] = ans;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dpMat(n+1, -1);
        int ans = dp(cost, 0, dpMat);
        ans = min(ans, dp(cost, 1, dpMat));
        return ans;
    }
};
