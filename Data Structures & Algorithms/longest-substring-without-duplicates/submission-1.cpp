class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.length();
        int ans = 0;
        map<char, int> freqChar;
        while(j<n){
            char presCh = s[j];
            freqChar[presCh]++;
            while(i<j && freqChar[presCh]>1){
                char tempCh = s[i];
                freqChar[tempCh]--;
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};
