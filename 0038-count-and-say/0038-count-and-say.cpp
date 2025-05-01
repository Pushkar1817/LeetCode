class Solution {
private:
    string runLenEncode(const string& str) {
        string ans = "";
        int cnt = 1;

        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += str[i - 1];
                cnt = 1;
            }
        }

        ans += to_string(cnt);
        ans += str.back();

        return ans;
    }

public:
    string countAndSay(int n) {
        string str = "1";

        for (int i = 1; i < n; i++) {
            str = runLenEncode(str);
        }

        return str;
    }
};
