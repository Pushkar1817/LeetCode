class Solution {
public:
    bool isCircularSentence(string s) {
        int pre = s[0] ;
        int st = s[0];
        for(int i = 1 ;i< s.size();i++){
            if(s[i] == ' '){
                continue;
            }
            if(s[i-1] == ' '){
                if(pre != s[i])
                    return false;
            }
            pre = s[i];
        }
        if(st != pre){
            return false;
        }
        return true;
    }
};