class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>sett(nums.begin(),nums.end());
        int maxi = 0 ;
        for(auto n : nums){
            if(sett.find(n-1) == sett.end()){
                int seq = 1;
                while(sett.find(n+seq) != sett.end()){
                    seq++;
                }
            maxi = max(maxi,seq);
            }
        }
        return maxi;
    }
};