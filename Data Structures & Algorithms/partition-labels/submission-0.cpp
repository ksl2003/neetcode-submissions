class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdxs (26, -1);
        int n = s.length();
        for(int i=0; i<n; i++){
            int charIdx = (int)s[i]-'a';
            lastIdxs[charIdx] = i;
        }

        int startIdx = 0;
        int lastIdx = 0;
        int presMaxGo = 0;
        // int presLen = 0;
        vector<int> ans;
        while(lastIdx<n){
            presMaxGo = max(presMaxGo,lastIdxs[s[lastIdx]-'a']);
            if(presMaxGo==lastIdx){
                ans.push_back((lastIdx-startIdx+1));
                startIdx = lastIdx+1;
            }
            lastIdx++;
        }
        if(lastIdx-startIdx)
        ans.push_back((lastIdx-startIdx));
        return ans;
    }
};
