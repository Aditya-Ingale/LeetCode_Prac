class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> graph(n);
        
        // Step 1: Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Step 2: Find connected components with their AND values using BFS
        vector<int> component(n, -1);
        vector<int> minAndValue(n, INT_MAX);
        int compID = 0;

        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                queue<int> q;
                q.push(i);
                component[i] = compID;
                int andValue = INT_MAX;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto& [neighbor, weight] : graph[node]) {
                        andValue &= weight;
                        if (component[neighbor] == -1) {
                            component[neighbor] = compID;
                            q.push(neighbor);
                        }
                    }
                }

                minAndValue[compID] = andValue;
                compID++;
            }
        }

        // Step 3: Process queries
        vector<int> answer;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] != component[t]) {
                answer.push_back(-1);
            } else {
                answer.push_back(minAndValue[component[s]]);
            }
        }
        return answer;
    }
};