class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqS(26, 0);
        int totalChars = 0;
        for(auto a: s){
            int idx = (int)a-'a';
            freqS[idx]++;
            totalChars++;
        }

        for(auto a: t){
            int idx = (int)a-'a';
            if(freqS[idx]){
                freqS[idx]--;
                totalChars--;
            }
            else if(freqS[idx]==0){
                return false;
            }
        }
        if(totalChars==0){
            return true;
        }
        return false;
    }
};
