class NumArray {
public:
    vector<int>pre;//locally banaya q ki dono function me use krna hai
    NumArray(vector<int>& nums) {
        int n=nums.size();
        pre.resize(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){// left==0 ex 0->3 tak ka sum chaiye to direct hi nums[3] ka aajayeg n
            return pre[right];
        }
        else{//left-1 isleye q ki 2-> 4 chaiye to left 2 ho jayega lekin 2 ke pahele se chaiye 2 nhi
            return pre[right]-pre[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */