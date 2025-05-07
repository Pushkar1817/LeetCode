class Solution {
public:
    int minTimeToReach(vector<vector<int>>& time) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;

        int n = time.size();
        int m = time[0].size();

        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));

        q.push({0, 0, 0});
        int dir[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            vector<int> top = q.top();
            q.pop();
            if (top[1] == n - 1 && top[2] == m - 1)
                return top[0];
            for (int i = 0; i < 4; i++) {
                int x = dir[i] + top[1];
                int y = dir[i + 1] + top[2];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                int move = 1 + max(top[0], time[x][y]);
                if (move < vis[x][y]) {
                    vis[x][y] = move;
                    q.push({move, x, y});
                }
            }
        }
        return -1;
    }
};