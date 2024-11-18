class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }
        if (k < 0) {
            k = abs(k);

            int val = 0;
            for(int i = 0 ;i<k ;i++){
                val+=code[i%n];
            }

            ans[k] = val;
            int ini = k+1;
            while(ini != k){
                val -= code[(ini-1-k+n)%n];
                val += code[(ini-1+n)%n];
                ans[ini%n] = val;
                ini = (ini+1)%n;
            }
        } 
        else {
            int val = 0;
            for (int i = 1; i <=k; i++) {
                val += code[i%n];
            }

            int ini = 1;
            ans[0] = val;

            while(ini != 0){
                val -= code[ini];
                val += code[(ini+k)%n];
                ans[ini] = val;
                ini = (ini+1)%n;
            }

        }

        return ans;
    }
};
