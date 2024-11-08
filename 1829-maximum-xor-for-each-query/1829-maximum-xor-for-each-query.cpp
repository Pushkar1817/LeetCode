class Solution {
private:
    // vector<int> numToBin(int num) {
    //     vector<int> bin(32, 0);
    //     for (int i = 31; i >= 0; i--) {
    //         int curr = (1 << i);
    //         if (curr <= num && num - curr >= INT_MIN) {  // Ensure no overflow
    //             bin[i] = 1;
    //             num -= curr;
    //         }
    //     }
    //     return bin;
    // }

    // vector<int> toggle(vector<int> num) {
    //     for (int i = 31; i >= 0; i--) {
    //         num[i] = num[i] == 0 ? 1 : 0;
    //     }
    //     return num;
    // }

    // int binToNum(vector<int> num) {
    //     int n = 0;
    //     for (int i = 31; i >= 0; i--) {
    //         if (num[i] == 1)
    //             n += (1 << i);
    //     }
    //     return n;
    // }

public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> xorValue(n);

        xorValue[0] = nums[0];
        for (int i = 1; i < n; i++) {
            xorValue[i] = (xorValue[i - 1] ^ nums[i]);
        }
        int maxXor = pow(2,maximumBit)-1;
        for (int i = 0; i < n; i++) {
            ans[n-i-1] = xorValue[i]^maxXor;
        }
        
        return ans;
    }
};
