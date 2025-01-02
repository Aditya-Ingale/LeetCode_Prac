class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Map to store the count of each number
        unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }

        // Set to store the frequencies
        unordered_set<int> frequencies;
        for (const auto& pair : countMap) {
            if (frequencies.find(pair.second) != frequencies.end()) {
                return false; // Duplicate frequency found
            }
            frequencies.insert(pair.second);
        }

        return true; // All frequencies are unique
    }
};