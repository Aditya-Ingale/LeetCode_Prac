class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for (auto &[ch, count] : freq) {
            if (count % 2 == 1) { // odd frequency
                maxOdd = max(maxOdd, count);
            } else { // even frequency
                minEven = min(minEven, count);
            }
        }

        // Since constraints guarantee at least one odd and one even frequency
        return maxOdd - minEven;
    }
};
