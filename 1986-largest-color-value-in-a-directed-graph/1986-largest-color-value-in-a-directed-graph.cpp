class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build the graph and indegree array
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // DP table: dp[i][c] = max number of color c (0 to 25) to node i
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;
        // Initialize queue with nodes of indegree 0
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        int result = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            int colorIdx = colors[node] - 'a';
            dp[node][colorIdx]++;
            result = max(result, dp[node][colorIdx]);

            for (int neighbor : graph[node]) {
                // Update neighbor's dp using current node's dp
                for (int c = 0; c < 26; ++c) {
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visited == n ? result : -1;
    }
};
