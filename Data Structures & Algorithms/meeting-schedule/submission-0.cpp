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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b) { return a.start < b.start; });

        int prevStart = intervals[0].start;
        int prevEnd = intervals[0].end;
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < prevEnd) {
                return false;
            }
            prevStart = intervals[i].start;
            prevEnd = intervals[i].end;
        }
        return true;
    }
};
