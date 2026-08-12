class Solution {
private:
    int dp(vector<int> &v, int index, bool isBuy, vector<vector<int>> &dpMat){
        if(index>=v.size()){
            return 0;
        }
        if(dpMat[index][isBuy]!=-1){
            return dpMat[index][isBuy];
        }

        int takeAns = 0;
        int notTakeAns = 0;
        if(isBuy){
            takeAns = (-v[index]) + dp(v, index+1, !isBuy, dpMat);
            notTakeAns = dp(v, index+1, isBuy, dpMat);
        }
        else{
            takeAns = (v[index]) + dp(v, index+2, !isBuy, dpMat);
            notTakeAns = dp(v, index+1, isBuy, dpMat);
        }

        return dpMat[index][isBuy] = max(takeAns, notTakeAns);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dpMat(n+1, vector<int> (2, -1));
        bool isBuy = true;
	    int ans = dp(prices, 0, isBuy, dpMat);
        return ans;
    }
};
