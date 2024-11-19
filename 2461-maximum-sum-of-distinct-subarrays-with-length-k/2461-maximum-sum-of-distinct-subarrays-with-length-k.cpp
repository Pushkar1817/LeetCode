class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        
        long long ans = 0;
        long long curr = 0 ;

        for(int i = 0 ;i<k ;i++){
            ump[nums[i]]++;
            curr+=nums[i];
        }
        if(ump.size() == k){
            ans = curr;
        }
        for(int i= k ;i< nums.size();i++){
            if(ump[nums[i-k]] == 1){
                ump.erase(nums[i-k]);
            }
            else
                ump[nums[i-k]]--;
            curr -= nums[i-k];
            curr += nums[i];
            ump[nums[i]]++;
            if(ump.size() == k)
                ans = max(ans, curr);
        }
        return ans;
    }
};