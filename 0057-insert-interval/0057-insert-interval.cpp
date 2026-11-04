#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       // 2 step

       // 1 - insert in correct spot

       bool inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            intervals.push_back(newInterval);
        }



       // 2 - merge overlapping ones 

       vector<int> current = intervals[0]; 
       vector<vector<int>> output;

        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) {
                current[1] = std::max(current[1], intervals[i][1]);
            }
            else {
                output.push_back(current);
                current = intervals[i];
            }
        }

        output.push_back(current);

        return output;
    }
};