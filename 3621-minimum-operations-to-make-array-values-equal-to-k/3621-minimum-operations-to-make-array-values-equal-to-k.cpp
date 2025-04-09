class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int minVal = INT_MAX;

        for (auto n : nums) {
            mp[n] = 1;                      // Storing unique values as keys
            minVal = min(minVal, n);        // Track minimum value
        }

        if (minVal < k) return -1;          // Can't increase smaller values to k

        int ans = mp.size();                // Total unique values
        if (mp[k]) ans--;                   // Don't need operation on 'k'

        return ans;
    }
};
