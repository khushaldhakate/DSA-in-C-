class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int end = intervals[0][1];
        int count = 0;

        for(int i = 1; i < n; i++)
        {
            int start = intervals[i][0];
            int e = intervals[i][1];

            if(start < end)
            {
                count++;
                end = min(end, e);
            }
            else
            {
                end = e;
            }
        }

        return count;
    }
};