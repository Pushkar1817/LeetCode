class Solution {
private:
    int timer = 0;
    vector<int> in, out, subtreeXor;

    void dfs(int node, int parent, const vector<vector<int>>& adj, const vector<int>& nums) {
        in[node] = ++timer;
        subtreeXor[node] = nums[node];
        for (int nei : adj[node]) {
            if (nei != parent) {
                dfs(nei, node, adj, nums);
                subtreeXor[node] ^= subtreeXor[nei];
            }
        }
        out[node] = ++timer;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        in.assign(n, 0);
        out.assign(n, 0);
        subtreeXor.assign(n, 0);

        dfs(0, -1, adj, nums);

        int totalXor = subtreeXor[0];
        int result = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            int u1 = edges[i][0], v1 = edges[i][1];
            if (in[u1] > in[v1]) swap(u1, v1); // v1 is child of u1

            for (int j = i + 1; j < edges.size(); j++) {
                int u2 = edges[j][0], v2 = edges[j][1];
                if (in[u2] > in[v2]) swap(u2, v2); // v2 is child of u2

                int x = subtreeXor[v1];
                int y = subtreeXor[v2];
                int z;

                if (isAncestor(v1, v2)) {
                    z = totalXor ^ x;
                    x = x ^ y;
                } else if (isAncestor(v2, v1)) {
                    z = totalXor ^ y;
                    y = y ^ x;
                } else {
                    z = totalXor ^ x ^ y;
                }

                int maxVal = max({x, y, z});
                int minVal = min({x, y, z});
                result = min(result, maxVal - minVal);
            }
        }

        return result;
    }
};
