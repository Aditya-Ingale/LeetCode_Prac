class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        int count = 0;

        // DFS to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> nodes;  // Store nodes in the component
                dfs(i, adj, visited, nodes);

                // Check if the component is complete
                bool isComplete = true;
                int size = nodes.size();
                for (int node : nodes) {
                    if (adj[node].size() != size - 1) { // Each node should be connected to (size-1) other nodes
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) count++;
            }
        }

        return count;
    }

private:
    void dfs(int node, vector<unordered_set<int>>& adj, vector<bool>& visited, vector<int>& nodes) {
        visited[node] = true;
        nodes.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes);
            }
        }
    }
};
