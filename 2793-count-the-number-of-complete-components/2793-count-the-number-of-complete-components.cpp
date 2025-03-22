class Solution {
public:
    // Function to find the representative (parent) of a node with path compression
    int findPar(int node, vector<int>& par) {
        if (node == par[node])
            return node;
        return par[node] = findPar(par[node], par);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 1);   // Stores the size of each component
        vector<int> par(n);        // Stores the parent of each node
        vector<int> edge(n, 0);    // Stores the number of edges in each component
        vector<int> rank(n, 0);    // Helps with union by rank

        // Initialize each node as its own parent (self-loop)
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Process each edge to unite components
        for (const auto& e : edges) {
            int u = e[0], v = e[1];

            int par1 = findPar(u, par);
            int par2 = findPar(v, par);

            if (par1 == par2) {
                edge[par1]++; // Same component, add edge count
            } else {
                // Union by rank
                if (rank[par1] == rank[par2]) {
                    par[par1] = par2;
                    count[par2] += count[par1];
                    edge[par2] += edge[par1] + 1;
                    rank[par2]++;
                } else if (rank[par1] > rank[par2]) {
                    par[par2] = par1;
                    count[par1] += count[par2];
                    edge[par1] += edge[par2] + 1;
                } else {
                    par[par1] = par2;
                    count[par2] += count[par1];
                    edge[par2] += edge[par1] + 1;
                }
            }
        }

        int res = 0;
        // Count components that are complete graphs
        for (int i = 0; i < n; i++) {
            if (i == par[i] && edge[i] == (count[i] * (count[i] - 1)) / 2) {
                res++;
            }
        }

        return res;
    }
};
