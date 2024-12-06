class Solution {
// private:
//     int solve(unordered_map<int,int>&banned,int n,int maxSum,int sum,int val,vector<vector<int>>&dp){
//         if(sum > maxSum ){
//             return 0;
//         }

//         if(dp[val-1][sum]!=-1)
//             return dp[val-1][sum];

//         int take = 0;
//         if((val>=1 && val<=n) && sum+val <= maxSum && !banned.count(val)){
//             take = 1+solve(banned,n,maxSum,sum+val,val+1,dp);
//         }
//         int notTake = 0;
//         if(banned.count(val)){
//             notTake = solve(banned,n,maxSum,sum,val+1,dp);
//         };
//         return dp[val-1][sum] =max(take,notTake);
//     }
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>ban;
        for(int i = 0 ;i<banned.size(); i++)
            ban[banned[i]] = 1;
        
        // vector<vector<int>>dp(n+1,vector<int>(maxSum+1,-1));
        // return solve(ban,n,maxSum,0,1,dp);
        // vector<vector<int>>dp(n+1,vector<int>(maxSum+1,0));

        // for(int val = n ; val > 0 ;val--){
        //     for(int sum = maxSum ;sum>=0 ; sum--){
        //         int take = 0;
        //         if((val>=1 && val<=n) && sum+val <= maxSum && !ban.count(val)){
        //             take = 1+dp[val+1-1][sum+val];
        //         }
        //         int notTake = 0;
        //         if(ban.count(val)){
        //             notTake = dp[val+1-1][sum];
        //         };
        //         dp[val-1][sum] =max(take,notTake);
        //     }
        // }
        // return dp[1][0];

        long long sum = 0;
        int count = 0;

        for(int i =1 ;i<=n ;i++){
            if(ban.count(i))
                continue;
            sum += i;
            if(sum > maxSum)
                break;
            count++;
        }
        return count;
    }
};