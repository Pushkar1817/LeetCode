class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) 
            return s;
            
        string ans;
        int freq = 1;  
        ans += s[0];
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                freq++;
            } 
            else {
                freq = 1;  
            }
            if (freq < 3) {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
