class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int start1=arr[0][0];
        int end1=arr[0][1];
        int i;
        for(i=1;i<n;i++)
        {
            int s=arr[i][0];
            int e=arr[i][1];

            if(end1>=s) //overlap
            {
                end1=max(end1,e);
                continue;
            }
            // push
            res.push_back({start1,end1});
            start1=s;
            end1=e;
        }
        res.push_back({start1,end1});
        return res;

}
};