class Solution {
private:
    bool isPrefixAndSufix(const string&str1 ,const string &str2){
        if(str1.size() > str2.size())
            return false;
        if(str1 != str2.substr(0,str1.size()))
            return false;
        if(str1 != str2.substr(str2.size()-str1.size()))
            return false;
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;

        for(int i= 0 ;i< words.size() ;i++){
            for(int j = i+1 ;j< words.size() ;j++){
                if(isPrefixAndSufix(words[i],words[j]))
                    ans++;
            }
        }
        return ans;
    }
};