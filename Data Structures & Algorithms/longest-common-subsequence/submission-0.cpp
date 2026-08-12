class Solution {
private:
    int dp(string &text1, string &text2, int i, int j, vector<vector<int>> &dpMat){
        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }
        if(dpMat[i][j]!=-1){
            return dpMat[i][j];
        }

        int ans = 0;
        if(text1[i]== text2[j]){
            ans = 1 + dp(text1, text2, i+1, j+1, dpMat);
        }
        else{
            ans = max(dp(text1, text2, i+1, j, dpMat), dp(text1, text2, i, j+1, dpMat));
        }
        return dpMat[i][j] = ans;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dpMat(text1.size()+1, vector<int> (text2.size()+1, -1));
        int ans = dp(text1, text2, 0, 0, dpMat);
        return ans;
    }
};
