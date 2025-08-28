class Solution {
private:
    vector<int>dir ={0, 1, 0, -1, 0};
    int solve(vector<vector<int>>&grid, int i, int j, vector<vector<bool>>&visited){
        if(i>= grid.size() || j>= grid[0].size() || i<0 || j<0 || visited[i][j] || grid[i][j] == 0){
            return 0;
        }
        visited[i][j] = true;

        int ans = 0;

        for(int d = 0; d< 4; d++){
            ans = max( ans, grid[i][j] + solve(grid, i+dir[d], j+dir[d+1], visited));
        }
        visited[i][j] = false;

        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ;i< n ;i++){
            for(int j = 0 ;j< m ;j++){
                if(grid[i][j] != 0){
                    vector<vector<bool>>visited(n,vector<bool>(m,false));
                    ans = max(ans, solve(grid, i, j, visited));
                }
            }
        }
        return ans;
    }
};