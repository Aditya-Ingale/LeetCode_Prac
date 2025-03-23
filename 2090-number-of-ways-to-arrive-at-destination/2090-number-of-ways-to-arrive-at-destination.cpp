class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Step 2: Dijkstra’s Algorithm
        vector<long long> dist(n, LLONG_MAX);  // Stores shortest time to reach each node
        vector<int> ways(n, 0);                // Stores number of ways to reach each node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Initialize start node
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue; // Ignore outdated entries

            for (auto [v, time] : adj[u]) {
                long long newDist = currDist + time;

                // If a new shortest path is found
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];  // Reset ways count
                    pq.push({newDist, v});
                } 
                // If another shortest path is found
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};