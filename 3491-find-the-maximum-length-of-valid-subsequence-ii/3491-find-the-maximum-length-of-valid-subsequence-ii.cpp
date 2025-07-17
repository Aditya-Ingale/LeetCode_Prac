class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            dp[i] = unordered_map<int, int>();
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                int len = dp[j].count(mod) ? dp[j][mod] + 1 : 2;
                dp[i][mod] = max(dp[i][mod], len);
                maxLen = max(maxLen, dp[i][mod]);
            }
        }
        return maxLen;
    }
};
