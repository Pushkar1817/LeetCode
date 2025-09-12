class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        string vowels = "AEIOUaeiou";

        for(auto i: s){
            if(vowels.find(i)!=string::npos){
                cnt++;
            }
        }
        if(cnt == 0){
            return false;
        }
        return true;
    }
};