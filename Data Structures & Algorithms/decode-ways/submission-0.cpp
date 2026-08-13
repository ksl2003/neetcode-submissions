class Solution {
private:
    int dp(string s, int i, vector<int> &dpMat){
        if(i>=s.length()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dpMat[i]!=-1){
            return dpMat[i];
        }
        int ans = 0;
        int firstDig = s[i]-'0';
        int secondDig = -1;
        if(i+1<s.length()){
            secondDig = s[i+1]-'0';
            if((firstDig*10 + secondDig)<=26){
                ans+=dp(s, i+2, dpMat);
            }
        }
        
        ans+=dp(s, i+1, dpMat);
        return dpMat[i] = ans;
    }

public:
    int numDecodings(string s) {
        vector<int> dpMat(s.length()+1, -1);
        int ans = dp(s, 0, dpMat);
        return ans;
    }
};
