class Solution {
private:
    int dp(int n, vector<int> &dpMat){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dpMat[n]!=-1){
            return dpMat[n];
        }

        int ans = dp(n-1, dpMat)+dp(n-2, dpMat);
        return dpMat[n] = ans;
    }

public:
    int climbStairs(int n) {
        vector<int> dpMat(n+1, -1);
        int ans = dp(n, dpMat);
        return ans;
    }
};
