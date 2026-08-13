class Solution {
private:
    int dp(vector<int>& coins, int amount, vector<int> &dpMat){
        if(amount<0){
            return 1e9;
        }
        if(amount==0){
            return 0;
        }
        if(dpMat[amount]!=-1){
            return dpMat[amount];
        }
        int ans = 1e9+1;
        for(int i=0; i<coins.size(); i++){
            ans = min(ans, 1 + dp(coins, amount-coins[i], dpMat));
        }
        return dpMat[amount] = ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dpMat(amount+1, -1);
        int ans = dp(coins, amount, dpMat);
        if(ans==1e9+1){
            return -1;
        }
        return ans;
    }
};
