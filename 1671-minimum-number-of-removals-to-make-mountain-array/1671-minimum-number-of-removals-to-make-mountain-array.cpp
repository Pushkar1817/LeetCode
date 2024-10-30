class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> preMin(nums.size(), 1), postMax(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for(int j = 0 ; j< i ;j++){
                if (nums[i] > nums[j]) {
                    preMin[i] = max(preMin[i],preMin[j] + 1);
                }
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            for(int j = nums.size()-1 ;j > i ;j--){
                if (nums[i] > nums[j]) {
                    postMax[i] = max(postMax[i],postMax[j] + 1);
                }
            }
        }

        int maxAns = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (preMin[i] > 1 && postMax[i] > 1) {
                maxAns = max(maxAns, preMin[i] + postMax[i] - 1);
            }
        }

        return nums.size() - maxAns;
    }
};
