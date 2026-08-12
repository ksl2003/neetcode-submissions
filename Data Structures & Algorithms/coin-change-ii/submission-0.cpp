class Solution {
private:
    int dp(int amount, vector<int> &coins, int index, vector<vector<int>> &dpMat){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(dpMat[amount][index]!=-1){
            return dpMat[amount][index];
        }
        int ans = 0;
        for(int i=index; i<coins.size(); i++){
            ans += dp(amount-coins[i], coins, i, dpMat);
        }
        return dpMat[amount][index] = ans;
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dpMat(amount+1, vector<int>(coins.size()+1, -1));
        int ans = dp(amount, coins, 0, dpMat);
        return ans;
    }
};
