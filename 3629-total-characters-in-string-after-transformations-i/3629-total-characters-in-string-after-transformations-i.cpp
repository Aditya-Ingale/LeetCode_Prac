class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> count(26, 0);
        
        // Initialize count from string s
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < t; ++i) {
            vector<long long> newCount(26, 0);
            for (int j = 0; j < 25; ++j) {
                newCount[j + 1] = (newCount[j + 1] + count[j]) % MOD;
            }
            // 'z' becomes 'a' and 'b'
            newCount[0] = (newCount[0] + count[25]) % MOD;
            newCount[1] = (newCount[1] + count[25]) % MOD;
            count = newCount;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + count[i]) % MOD;
        }
        return result;
    }
};
