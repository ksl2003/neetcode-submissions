class Solution {
public:
    string longestPalindrome(string s) {
        int longStrInd = 0;
        int longStrLen = 1;
        int n = s.length();

        // checking for odd len
        for(int i=0; i<n; i++){
            int presMid = i;
            int leftInd = i-1;
            int rightInd = i+1;
            int presLen = 1;
            while(leftInd>=0 && rightInd<n && s[leftInd]==s[rightInd]){
                presLen += 2;
                longStrLen = max(longStrLen, presLen);
                if(presLen==longStrLen){
                    longStrInd = leftInd;
                }
                leftInd--;
                rightInd++;
            }
        }

        // For even Len
        for(int i=0; i<n; i++){
            int presMid = i;
            int leftInd = i-1;
            int rightInd = i;
            int presLen = 0;
            while(leftInd>=0 && rightInd<n && s[leftInd]==s[rightInd]){
                presLen += 2;
                longStrLen = max(longStrLen, presLen);
                if(presLen==longStrLen){
                    longStrInd = leftInd;
                }
                leftInd--;
                rightInd++;
            }
        }
        return s.substr(longStrInd, longStrLen);
    }
};
