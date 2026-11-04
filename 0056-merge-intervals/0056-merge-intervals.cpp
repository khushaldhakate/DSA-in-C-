class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(end>=s){
                //merge hoga start to less hi rahega so 
                end=max(end,e);
            }else{
                res.push_back({start,end});
                start=s;
                end=e;
            }
        }

        res.push_back({start,end});
        return res;

    }
};