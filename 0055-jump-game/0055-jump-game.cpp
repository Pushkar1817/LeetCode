class Solution {
// private:
//     bool solve(vector<int>&nums,int ind,vector<int>&dp){
//         if(ind >= nums.size()-1)
//             return 1;
//         if(dp[ind]!= -1){
//             return dp[ind];
//         }
//         bool mini = false;
//         for(int j= 1 ; j<=nums[ind] ;j++)
//             mini = mini || solve(nums,ind+j,dp);
//         return dp[ind] = mini;
//     }
public:
    bool canJump(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);
        // return solve(nums,0,dp);
        vector<bool>dp(nums.size(),false);
        dp[nums.size()-1] = true;
        for(int i = nums.size()-2;i>=0 ;i--){
            bool reach = false;
            for(int j = 1 ;j<= nums[i] && j+i<nums.size();j++){
                reach = reach || dp[i+j];
            }
            dp[i] = reach;
        }
        return dp[0];
    }
};