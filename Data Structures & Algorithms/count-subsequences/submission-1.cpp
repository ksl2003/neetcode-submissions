class Solution {
private:
    int dp(string &s, string &t, int i, int j, vector<vector<int>> &dpMat){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dpMat[i][j]!=-1){
            return dpMat[i][j];
        }
        int ans = 0;
        if(s[i]==t[j]){
            ans += dp(s, t, i+1, j+1, dpMat) + dp(s, t, i+1, j, dpMat);
        }
        else{
            ans += dp(s, t, i+1, j, dpMat);
        }
        return dpMat[i][j] = ans;
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dpMat(s.length()+1, vector<int> (t.length(), -1));
        int ans = dp(s, t, 0, 0, dpMat);
        return ans;
    }
};
