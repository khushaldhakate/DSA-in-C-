class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;
        int n = intervals.size();
        bool insert = false;

        // Insertion
        for(int i = 0; i < n; i++) {
            if(insert == false && intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                insert = true;
            }

            res.push_back(intervals[i]);
        }

        if(insert == false) {
            res.push_back(newInterval);
        }

        // Overlapping
        int start = res[0][0];
        int end = res[0][1];

        int n1 = res.size();
        vector<vector<int>> ans;

        for(int i = 1; i < n1; i++) {

            int s = res[i][0];
            int e = res[i][1];

            if(end >= s) {
                end = max(end, e);
            }
            else {
                ans.push_back({start, end});
                start = s;
                end = e;
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};