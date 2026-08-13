class Solution {
private:
    bool dp(string s, map<string, bool> &mp, int i, vector<int> &dpMat){
        if(i>=s.length()){
            return true;
        }
        if(dpMat[i]!=-1){
            return dpMat[i];
        }

        string test = "";
        bool ans = false;
        for(int index = i; index<s.length(); index++){
            test.push_back(s[index]);
            if(mp.count(test)){
                ans = ans || dp(s, mp, index+1,dpMat);
            }
        }
        return dpMat[i] = ans;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> mp;
        for(auto a: wordDict){
            mp[a]=true;
        }
        vector<int> dpMat(s.length()+1, -1);
        bool ans = dp(s, mp, 0, dpMat);
        return ans;
    }
};
