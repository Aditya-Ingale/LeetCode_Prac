class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(26, vector<int>(t + 1, 0));

        // Base case: after 0 transformations, each char is itself
        for (int c = 0; c < 26; ++c) {
            dp[c][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= t; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (c == 25) {
                    dp[c][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
                } else {
                    dp[c][i] = dp[c + 1][i - 1];
                }
            }
        }

        // Calculate final length
        long long result = 0;
        for (char ch : s) {
            result = (result + dp[ch - 'a'][t]) % MOD;
        }

        return (int)result;
    }
};
