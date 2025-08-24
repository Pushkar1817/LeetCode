class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int last0 = -1;
        int ans = 0;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (last0 != -1) {
                    left = last0 + 1;
                }
                last0 = i;
            }
            ans = max(ans, i - left);
        }

        return ans;
    }
};
