class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> freqs;
        for (auto& [ch, f] : freq) {
            freqs.push_back(f);
        }

        int res = INT_MAX;
        int max_freq = *max_element(freqs.begin(), freqs.end());

        for (int target = 1; target <= max_freq; ++target) {
            int deletions = 0;
            for (int f : freqs) {
                if (f > target + k) {
                    deletions += f - (target + k);  // Reduce frequency
                } else if (f < target) {
                    deletions += f;  // Delete entire character group
                }
                // else: in range [target, target + k] => no deletion needed
            }
            res = min(res, deletions);
        }

        return res;
    }
};
