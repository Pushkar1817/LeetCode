class Solution {
private:
    static int setBits(int num) {
        int count = 0;
        for (int i = 31; i >= 0; --i) {
            if ((num >> i) & 1) {
                count++;
            }
        }
        return count;
    }

public:
    bool canSortArray(vector<int>& nums) {
        vector<int> check(nums);
        sort(check.begin(), check.end()); 
        
        unordered_map<int, int> ump;
        for (int num : nums) {
            ump[num] = setBits(num);
        }

        for (int i =0; i < nums.size()-1; i++) {
            for (int j = 0; j < nums.size()-i-1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (ump[nums[j]] != ump[nums[j + 1]])
                        continue; 
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for(int i = 0 ;i< check.size() ;i++){
            cout<<nums[i]<<"  "<<check[i]<<endl;
        }
        return check == nums;
    }
};
