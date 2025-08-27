class Solution {
public:
    vector<vector<int>> dir = {{1,1},{1,-1},{-1,-1},{-1,1}};
    // clockwise mapping
    vector<int> nextDir = {1,2,3,0};

    int solve(vector<vector<int>>& grid, int i, int j, bool turn, int d, int step) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;

        int expected;
        if (step == 0) expected = 1;       // must start with 1
        else if (step % 2 == 1) expected = 2;  // odd steps expect 2
        else expected = 0;                     // even steps after 0 expect 0

        if (grid[i][j] != expected) return 0;

        int ans = 1; // count current cell

        // continue straight
        ans = max(ans, 1 + solve(grid, i + dir[d][0], j + dir[d][1], turn, d, step + 1));

        // if we haven’t turned yet, try the clockwise turn
        if (turn) {
            int nd = nextDir[d];
            ans = max(ans, 1 + solve(grid, i + dir[nd][0], j + dir[nd][1], false, nd, step + 1));
        }

        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { // must start with 1
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, solve(grid, i, j, true, d, 0));
                    }
                }
            }
        }
        return ans;
    }
};
