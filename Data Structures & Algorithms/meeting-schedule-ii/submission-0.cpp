/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTimes, endTimes;
        int n = intervals.size();
        for(auto a: intervals){
            startTimes.push_back(a.start);
            endTimes.push_back(a.end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int s = 0, e = 0;
        int ans = 0;
        int presCnt = 0;
        while(s<n && e<n){
            // int cnt = 0;
            while(s<n && e<n && startTimes[s]<endTimes[e]){
                s++;
                presCnt++;
                ans = max(ans, presCnt);
            }
            while(e<n && s<n && startTimes[s]>=endTimes[e]){
                e++;
                presCnt--;
                ans = max(ans, presCnt);
            }
        }
        return ans;
    }
};
