class Solution {
private:
    int checkCons(int left, int right, vector<int>& nums) {
        int maxi = nums[left];
        for (int i = left + 1; i <= right; i++) {
            if (nums[i]-1 !=  nums[i - 1]) {
                return INT_MIN;
            }
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        if (k == 1) {
            return vector<int>(nums.begin(), nums.end());
        }

        for (int left = 0; left <= n - k; left++) {
            int right = left + k - 1;
            int store = checkCons(left, right, nums);
            if (store != INT_MIN) {
                ans[left] = store;
            }
        }

        return ans;
    }
};
