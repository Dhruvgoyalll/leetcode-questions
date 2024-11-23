class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int first, second;
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        if(n == 1) return intervals;
        
        ans.push_back({intervals[0][0], intervals[0][1]});// inserted first interval in ans so it will become easier to compare
        for(int i = 1; i < n; i++){
            first = intervals[i][0];
            second = ans.back()[1];
            
            if(second >= first){
                
                ans.back()[1] = max(intervals[i][1], second);//max because case can be [1,5] [2,3]
                
            }
            else{
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        return ans;
    }
};