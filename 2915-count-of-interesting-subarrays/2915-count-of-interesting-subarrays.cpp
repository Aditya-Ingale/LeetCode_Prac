class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1; // Base case: prefix sum is 0 initially
        long long result = 0;
        int prefixMod = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefixMod = (prefixMod + 1) % modulo;
            } else {
                prefixMod = prefixMod % modulo;
            }

            // To find number of prefix[i] such that (prefixMod - prefix[i]) % modulo == k
            // => prefix[i] ≡ (prefixMod - k + modulo) % modulo
            int want = (prefixMod - k + modulo) % modulo;
            if (freq.count(want)) {
                result += freq[want];
            }

            freq[prefixMod]++;
        }

        return result;
    }
};
