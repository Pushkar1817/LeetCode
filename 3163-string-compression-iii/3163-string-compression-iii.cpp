class Solution {
public:
    string compressedString(string word) {
        // map<char,int>mp;
        // for(int i = 0 ;i< word.size() ;i++){
        //     mp[word[i]]++;
        // }
        // string comp = "";
        // unordered_set<char>check;
        // for(auto i : word){
        //     if(check.find(i)!=check.end()){
        //         continue;
        //     }

        //     int freq = mp[i];
        //     while(freq > 9){
        //         comp+='9';
        //         comp+=i;
        //         freq -= 9;
        //     }
        //     comp += freq+'0';
        //     comp += i;
        //     check.insert(i);
        // }
        // return comp;

        string comp = "";

        for(int i = 0 ;i< word.size() ;i++){
            int freq = 0 ;
            int j = i;
            while(true){
                if(word[j]!=word[i])
                    break;
                j++;
                freq++;
            }

            while(freq > 9){
                comp+='9';
                comp+=word[i];
                freq -= 9;
            }
            comp += freq+'0';
            comp += word[i];
            i = j-1;
        }
        return comp;
    }
};