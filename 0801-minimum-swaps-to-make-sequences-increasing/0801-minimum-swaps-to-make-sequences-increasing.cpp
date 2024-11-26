class Solution {
// private:
//     int helper(vector<int>& nums1, vector<int>& nums2, int ind, int swaps, vector<vector<int>>& dp,int prev1 ,int prev2) {
//         if (ind >= nums1.size())
//             return 0;

//         if (dp[ind][swaps] != -1) 
//             return dp[ind][swaps];

//         int notSwapped = INT_MAX, swapped = INT_MAX;
//         if(swaps)
//             swap(prev1,prev2);
//         if (ind == 0 || (nums1[ind] > prev1 && nums2[ind] > prev2)) {
//             notSwapped = helper(nums1, nums2, ind + 1,0, dp,nums1[ind],nums2[ind]);
//         }

//         if (ind == 0 || (nums1[ind] > prev2 && nums2[ind] > prev1)) {
//             swapped = 1 + helper(nums1, nums2, ind + 1,1, dp,nums1[ind],nums2[ind]);
//         }

//         return dp[ind][swaps] = min(notSwapped, swapped);
//     }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return helper(nums1, nums2, 0, 0, dp,-1,-1); 
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        int swapp = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;
        for(int ind = n-1; ind >=0  ;ind--){
            for(int swaps = 0 ; swaps< 2 ;swaps++){
                int notSwapped = INT_MAX, swapped = INT_MAX;
                int prev1 = -1;
                int prev2 = -1;
                if(ind!=0){
                    prev1 = nums1[ind-1];
                    prev2 = nums2[ind-1];
                }
                if(swaps)
                    swap(prev1,prev2);

                if (ind == 0 || (nums1[ind] > prev1 && nums2[ind] > prev2)) {
                    notSwapped = noSwap;
                }

                if (ind == 0 || (nums1[ind] > prev2 && nums2[ind] > prev1)) {
                    swapped = 1 + swapp;
                }
                int ans = min(swapped,notSwapped);
                if(swaps)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swapp = currSwap;
            noSwap = currNoSwap;
        }
        return min(swapp,noSwap);
    }
};
