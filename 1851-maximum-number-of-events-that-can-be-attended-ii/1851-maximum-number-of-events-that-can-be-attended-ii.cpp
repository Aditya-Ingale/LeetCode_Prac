class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        // Sort events based on their end day
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Extract end times for binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i)
            endTimes[i] = events[i][1];

        // DP table: dp[i][j] = max value using first i events and attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0], end = events[i - 1][1], val = events[i - 1][2];
            
            // Find the last event that ends before current event's start
            int prev = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin();
            
            for (int j = 1; j <= k; ++j) {
                // Max of skipping or including this event
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + val);
            }
        }

        return dp[n][k];
    }
};
