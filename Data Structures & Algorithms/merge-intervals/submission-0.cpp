class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0;
        int n = intervals.size();

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        while(i<n){
            while(i<n-1 && intervals[i][1]<intervals[i+1][0]){
                ans.push_back(intervals[i]);
                i++;
            }

            int presStart = intervals[i][0];
            int presEnd = intervals[i][1];
            while(i<n && presEnd>=intervals[i][0]){
                presStart = min(presStart, intervals[i][0]);
                presEnd = max(presEnd, intervals[i][1]);
                i++;
            }
            ans.push_back({presStart, presEnd});
        }
        return ans;
    }
};
