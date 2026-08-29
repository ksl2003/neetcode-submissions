class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int presMinBought = prices[0];
        int n = prices.size();
        for(int i=1; i<n; i++){
            ans = max(ans, prices[i]-presMinBought);
            presMinBought = min(presMinBought, prices[i]);
        }
        return ans;
    }
};
