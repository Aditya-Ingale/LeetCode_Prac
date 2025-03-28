class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer(queries.size(), 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<pair<int, int>> indexedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            indexedQueries.push_back({queries[i], i});
        }
        sort(indexedQueries.begin(), indexedQueries.end());
        
        pq.push({grid[0][0], 0});
        visited[0][0] = true;
        int count = 0;
        
        for (auto& [query, idx] : indexedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [value, pos] = pq.top(); pq.pop();
                int r = pos / n, c = pos % n;
                count++;
                
                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        pq.push({grid[nr][nc], nr * n + nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            answer[idx] = count;
        }
        
        return answer;
    }
};
