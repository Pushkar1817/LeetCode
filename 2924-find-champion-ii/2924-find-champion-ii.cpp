class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // vector<vector<int>>revAdj(n);
        // for(int i = 0 ;i< edges.size() ;i++){
        //     revAdj[edges[i][1]].push_back(edges[i][0]);
        // }
        // int ans = -1;
        // for(int i = 0 ;i< n; i++){
        //     if(!revAdj[i].size()){
        //         if(ans!=-1)
        //             return -1;
        //         ans = i;
        //     }
        // }
        // return ans ;
        vector<bool>weaker(n,false);
        for(int i = 0 ; i<edges.size() ;i++){
            weaker[edges[i][1]] = true;
        }
        int ans = -1;
        for(int i = 0 ;i < n ; i++){
            if(weaker[i] == false){
                if(ans != -1)  
                    return -1;
                ans = i;
            }
        }
        return ans ;
    }
};