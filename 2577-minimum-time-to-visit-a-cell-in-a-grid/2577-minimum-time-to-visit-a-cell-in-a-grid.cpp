class Solution { 
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][0] != 0 || (grid[1][0]>1 && grid[0][1] >1)){
            return -1;
        }
        vector<int> dir= {0,1,0,-1,0};
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto[t,i,j] = pq.top();
            pq.pop();
            if(i == n-1  && j == m-1)
                return t;
            for(int d = 0 ;d<4 ; d++){
                int newI = i+dir[d];
                int newJ = j+dir[d+1];

                if(newI < n && newJ < m && newI >= 0 && newJ >= 0 ){
                    int nextTime = max(t+1,grid[newI][newJ]+(((grid[newI][newJ]-t)&1)?0:1));
                    if(dist[newI][newJ] > nextTime){
                        dist[newI][newJ] = nextTime;
                        pq.push({nextTime,newI,newJ});
                    }
                }
            }
        }
        return -1;
    }
};