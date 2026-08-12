class Solution {
private:
    int dp(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dpMat){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dpMat[i][j]!=-1){
            return dpMat[i][j];
        }
        int ans = 0;
        if(i<matrix.size()-1 && (matrix[i+1][j]>matrix[i][j])){
            ans = max(ans, 1+dp(matrix, i+1, j, dpMat));
        }
        if(i>0 && (matrix[i-1][j]>matrix[i][j])){
            ans = max(ans, 1+dp(matrix, i-1, j, dpMat));
        }
        if(j<matrix[0].size()-1 && (matrix[i][j+1]>matrix[i][j])){
            ans = max(ans, 1+dp(matrix, i, j+1, dpMat));
        }
        if(j>0 && (matrix[i][j-1]>matrix[i][j])){
            ans = max(ans, 1+dp(matrix, i, j-1, dpMat));
        }
        return dpMat[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dpMat(rows+1, vector<int> (cols, -1));
        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans = max(ans, dp(matrix, i, j, dpMat));
            }
        }
        return ans+1;
    }
};
