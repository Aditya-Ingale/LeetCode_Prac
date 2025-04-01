class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // DP array to store max points from i to end
        
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int next = i + brainpower + 1;
            
            // Take the question
            long long take = points + (next < n ? dp[next] : 0);
            
            // Skip the question
            long long notTake = dp[i + 1];
            
            // Store the best choice at dp[i]
            dp[i] = max(take, notTake);
        }
        
        return dp[0]; // Maximum points possible from question 0
    }
};
