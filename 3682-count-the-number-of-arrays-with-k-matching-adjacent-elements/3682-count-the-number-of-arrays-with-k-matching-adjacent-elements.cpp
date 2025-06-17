class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 1e5 + 5;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials() {
        fact.resize(MAX);
        invFact.resize(MAX);
        fact[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAX - 1] = modPow(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials();
        long long ways = comb(n - 1, k);                      // choose positions for equality
        ways = (ways * m) % MOD;                              // first element choice
        ways = (ways * modPow(m - 1, n - 1 - k)) % MOD;       // transitions
        return ways;
    }
};
