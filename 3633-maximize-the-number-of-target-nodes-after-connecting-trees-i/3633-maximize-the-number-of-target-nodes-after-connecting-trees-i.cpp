class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build trees
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        // For Tree2: count of nodes reachable from each node within distance k
        vector<int> tree2Counts(m, 0);
        for (int i = 0; i < m; ++i) {
            tree2Counts[i] = bfsWithinK(tree2, i, k - 1); // -1 because edge will be added later
        }

        // For each node in Tree1, find best connection
        vector<int> answer(n);
        for (int u = 0; u < n; ++u) {
            int tree1Reach = bfsWithinK(tree1, u, k);
            int maxTotal = 0;
            for (int v = 0; v < m; ++v) {
                int combined = tree1Reach + tree2Counts[v];
                maxTotal = max(maxTotal, combined);
            }
            answer[u] = maxTotal;
        }

        return answer;
    }

private:
    int bfsWithinK(const vector<vector<int>>& tree, int start, int k) {
        int count = 0;
        int n = tree.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front(); q.pop();
            if (dist > k) continue;
            count++;
            for (int nei : tree[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, dist + 1});
                }
            }
        }
        return count;
    }
};
