class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAXN = 10005;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void computeFactorials(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    int nCr(int n, int r) {
        if (r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        computeFactorials(n); // For binomial coefficients

        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));

        for (int i = 1; i <= maxValue; ++i)
            dp[i][1] = 1;

        for (int len = 2; len <= 14; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = 2 * i; j <= maxValue; j += i) {
                    dp[j][len] = (dp[j][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        int result = 0;
        for (int val = 1; val <= maxValue; ++val) {
            for (int len = 1; len <= 14; ++len) {
                if (dp[val][len] == 0) continue;
                result = (result + 1LL * dp[val][len] * nCr(n - 1, len - 1) % MOD) % MOD;
            }
        }

        return result;
    }
};
