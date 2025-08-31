class Solution {
private:
    int calc(vector<int>arr, int both){
        int mx = *max_element(arr.begin(), arr.end());
        int total = accumulate(arr.begin(), arr.end(), 0)+both;
        mx = max(mx, both);

        return min(total/2, total-mx);
    }
public:
    int score(vector<string>& cards, char x) {
        vector<int>left(10),right(10);

        int both  = 0 ;

        for(auto i: cards){
            if(i[0] == x && i[1] == x){
                both++;
            }
            else if(i[0] ==x)
                left[i[1]-'a']++;
            else if(i[1] == x)
                right[i[0]-'a']++;
        }

        int ans = 0;

        for(int i = 0 ;i<=both ; i++){
            ans = max(ans, calc(right, i) + calc(left, both-i));
        }
        return ans;
    }
};