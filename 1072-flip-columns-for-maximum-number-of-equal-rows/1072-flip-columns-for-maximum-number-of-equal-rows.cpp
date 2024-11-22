class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        unordered_map<string, int> freq;
        
        for (const auto& row : mat) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) 
                    pattern += to_string(bit);
            } else {
                for (int bit : row) 
                    pattern += to_string(bit ^ 1);
            }
            freq[pattern]++;
        }
        
        int maxFreq = 0;
        for (const auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};