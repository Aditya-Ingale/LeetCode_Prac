class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false), seen(n, false), boxAvailable(n, false);
        queue<int> q;
        int totalCandies = 0;

        for (int box : initialBoxes) {
            boxAvailable[box] = true;
            if (status[box] == 1) {
                q.push(box);
                seen[box] = true;
            }
        }

        while (!q.empty()) {
            int box = q.front(); q.pop();
            totalCandies += candies[box];

            // Acquire keys
            for (int key : keys[box]) {
                hasKey[key] = true;
                if (boxAvailable[key] && !seen[key]) {
                    q.push(key);
                    seen[key] = true;
                }
            }

            // Add contained boxes
            for (int contained : containedBoxes[box]) {
                boxAvailable[contained] = true;
                if (status[contained] == 1 || hasKey[contained]) {
                    if (!seen[contained]) {
                        q.push(contained);
                        seen[contained] = true;
                    }
                }
            }
        }

        return totalCandies;
    }
};
