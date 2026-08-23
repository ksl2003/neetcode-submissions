class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--){
            int presEle = temperatures[i];
            int presInd = i;

            while(!s.empty() && s.top().first<=presEle){
                s.pop();
            }
            int presGreat = -1;
            int presGreatInd = -1;
            if(!s.empty()){
                presGreat = s.top().first;
                presGreatInd = s.top().second;
                ans[i] = (presGreatInd-presInd);
            }
            s.push({presEle, presInd});
        }
        return ans;
    }
};
