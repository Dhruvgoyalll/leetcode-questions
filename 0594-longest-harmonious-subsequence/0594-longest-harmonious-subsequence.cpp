class Solution {
public:
    int findLHS(vector<int>& nums) {
        int left=0,right=1,storing=0;
        int n=nums.size();
       sort(nums.begin(),nums.end());
        while(right<n)
        {
            if(nums[right]-nums[left]==1){
                storing=max(storing,right-left+1);

            }
            while(nums[right]-nums[left]>1){
                ++left;
            }
            ++right;
        }
        return storing;
        
    }
};