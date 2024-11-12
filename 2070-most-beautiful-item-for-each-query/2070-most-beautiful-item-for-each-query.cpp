class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int,int>ump;
        vector<int>ans(queries);
        sort(items.begin(),items.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
        });
        // sort(items.begin(),items.end());
        sort(queries.begin(),queries.end());
        int j = 0,preMax = 0 ;
        for(int i = 0 ;i< queries.size() ;i++){
            while(j<items.size() && items[j][0] <= queries[i]){
                preMax = max(preMax,items[j][1]);
                j++;
            }
            ump[queries[i]] = preMax;
        }

        for(int i= 0 ; i< queries.size() ;i++){
            ans[i] = ump[ans[i]];
        }

        return ans;
    }
};