class Solution {
private:
    int dp(string &word1, string &word2, int i, int j, vector<vector<int>> &dpMat){
        if(i==word1.length() && j==word2.length()){
            return 0;
        }
        if(dpMat[i][j]!=-1){
            return dpMat[i][j];
        }
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = dp(word1, word2, i+1, j+1, dpMat);
        }
        else{
            ans = 1 + min(dp(word1, word2, i+1, j, dpMat),min(dp(word1, word2, i, j+1, dpMat), dp(word1, word2, i+1, j+1, dpMat)));
        }
        return dpMat[i][j] = ans;
    }

public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dpMat(len1+1, vector<int> (len2+1, -1));
        int ans = dp(word1, word2, 0, 0, dpMat);
        return ans;
    }
};
