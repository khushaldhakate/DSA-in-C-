class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //Compare krne ke liye kaam aaata hai kisise to (target-sum) ki value compare karege like find smalledt digit
        int closest=nums[0]+nums[1]+nums[2];
        for(int k=0;k<n-2;k++){
            int i=k+1;
            int j=n-1;
            while(i<j){
                int sum=nums[k]+nums[i]+nums[j];
                if(abs(target-sum)<abs(target-closest)){// yaaha specail target - sum se diff nikalenge jo diff kam aayega wo close value hoga
                    closest=sum;
                }else if(sum<target){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return closest;


    }
};