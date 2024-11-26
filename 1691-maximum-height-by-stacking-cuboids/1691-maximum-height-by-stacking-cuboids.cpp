class Solution {
// private:
//     int helper(vector<vector<int>>&cuboids,int ind , int prevInd,vector<vector<int>>&dp){
//         if(ind >= cuboids.size())
//             return 0;
//         if(dp[ind][prevInd+1]!=-1)
//             return dp[ind][prevInd+1];
//         int take = 0;
//         if(prevInd == -1 || (cuboids[ind][2] <= cuboids[prevInd][2] && cuboids[ind][1] <= cuboids[prevInd][1] && cuboids[ind][0] <= cuboids[prevInd][0] )){
//             take = cuboids[ind][0] + helper(cuboids,ind+1,ind,dp);
//         }
//         int notTake = helper(cuboids,ind+1,prevInd,dp);
//         return dp[ind][prevInd+1] = max(take,notTake);
//     }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto&cuboid : cuboids)
            sort(cuboid.rbegin(),cuboid.rend());
        sort(cuboids.rbegin(),cuboids.rend());

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

        for(int ind = n-1 ; ind>=0 ; ind--){
            for(int prevInd = ind-1 ; prevInd>= -1 ;prevInd--){
                int take = 0;
                if(prevInd == -1 || (cuboids[ind][2] <= cuboids[prevInd][2] && cuboids[ind][1] <= cuboids[prevInd][1] && cuboids[ind][0] <= cuboids[prevInd][0] )){
                    take = cuboids[ind][0] + next[ind+1];
                }
                int notTake = next[prevInd+1];
                curr[prevInd+1] = max(take,notTake);
            }
            next = curr;
        }
        // return helper(cuboids,0,-1,dp);
        return next[0];
    }
};