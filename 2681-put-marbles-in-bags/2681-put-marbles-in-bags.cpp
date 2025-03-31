class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairSums;
        
        // Compute pairwise sums of adjacent elements
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }
        
        // Sort the pairwise sums
        sort(pairSums.begin(), pairSums.end());
        
        long long minScore = 0, maxScore = 0;
        
        // Compute the minimum and maximum score differences
        for (int i = 0; i < k - 1; i++) {
            minScore += pairSums[i];              // Take smallest (k-1) sums
            maxScore += pairSums[n - 2 - i];      // Take largest (k-1) sums
        }
        
        return maxScore - minScore;
    }
};