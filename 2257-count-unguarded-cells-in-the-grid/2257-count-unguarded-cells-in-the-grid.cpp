class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (auto& wall : walls) 
            grid[wall[0]][wall[1]] = 1;
        for (auto& guard : guards) 
            grid[guard[0]][guard[1]] = 2;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& guard : guards) {
            for (auto& dir : directions) {
                int x = guard[0] + dir.first, y = guard[1] + dir.second;
                while (x >= 0 && x < m && y >= 0 && y < n &&( grid[x][y] == 0||grid[x][y] == 3) ) {
                    grid[x][y] = 3; 
                    x += dir.first;
                    y += dir.second;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    cout<<"("<<i<<","<<j<<")"<<endl;
                }
            }
        }

        return ans;
    }
};
