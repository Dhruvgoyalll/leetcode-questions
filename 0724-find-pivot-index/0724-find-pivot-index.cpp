class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int i=0,sums=0;
        for(int &x:nums){
            sums+=x;
        }
        
        
        int cs=0;
        for(i=0;i<n;i++){
            int left=cs;
            int right=sums-cs-nums[i];
        if(left==right)
        return i;
        cs+=nums[i];
        }
        return -1;
    }
    
};