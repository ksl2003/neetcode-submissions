class Solution {
private:
    int dp(int m, int n, int i, int j, vector<vector<int>> &dpMat){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dpMat[i][j]!=-1){
            return dpMat[i][j];
        }
        int ans = 0;
        ans += dp(m, n, i+1, j, dpMat);
        ans += dp(m, n, i, j+1, dpMat);
        return dpMat[i][j] = ans;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dpMat(m+1, vector<int> (n+1, -1));
        int ans = dp(m, n, 0, 0, dpMat);
        return ans;
    }
};
