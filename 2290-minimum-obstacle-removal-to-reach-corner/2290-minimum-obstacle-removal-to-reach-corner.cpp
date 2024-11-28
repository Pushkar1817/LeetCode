class Solution {
private:
    vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto[w,i,j] = pq.top();
            pq.pop();
            if(i == n-1 && j == m-1)
                return w;
            for(int d= 0 ;d<4;d++){
                int newI = i+dir[d][0];
                int newJ = j+dir[d][1];
                if(newI >=0 && newJ >= 0 && newI <n &&newJ < m ){
                    if(dist[newI][newJ] > w+grid[newI][newJ]){
                        dist[newI][newJ] = w+grid[newI][newJ];
                        pq.push({w+grid[newI][newJ],newI,newJ});
                    }
                }
            }
        }

        return -1;
    }
};