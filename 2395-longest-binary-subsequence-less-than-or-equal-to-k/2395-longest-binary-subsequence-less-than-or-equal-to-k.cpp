class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        int power = 0;

        // Traverse from right to left (least significant to most significant bit)
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;  // zero can always be added
            } else {
                // Only consider if including this '1' keeps value <= k
                if (power < 32) {  // to prevent overflow
                    if (value + (1LL << power) <= k) {
                        value += (1LL << power);
                        count++;
                    }
                }
            }
            power++;
        }

        return count;
    }
};
