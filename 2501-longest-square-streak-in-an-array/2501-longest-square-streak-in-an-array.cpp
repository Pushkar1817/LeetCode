class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int lastAns = 1;

        for (int num : nums) {
            int root = sqrt(num);
            if (root * root == num && dp.count(root)) {
                dp[num] = dp[root] + 1;
            } 
            else {
                dp[num] = 1;
            }
            lastAns = max(lastAns, dp[num]);
        }

        return lastAns > 1 ? lastAns : -1; 
    }
};
