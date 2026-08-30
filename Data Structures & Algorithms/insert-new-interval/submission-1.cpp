class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ansList;
        int n = intervals.size();

        int i = 0;

        // 1. Intervals completely before newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            ansList.push_back(intervals[i]);
            i++;
        }

        // 2. Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // 3. Add merged newInterval
        ansList.push_back(newInterval);

        // 4. Remaining intervals
        while(i < n){
            ansList.push_back(intervals[i]);
            i++;
        }

        return ansList;
    }
};