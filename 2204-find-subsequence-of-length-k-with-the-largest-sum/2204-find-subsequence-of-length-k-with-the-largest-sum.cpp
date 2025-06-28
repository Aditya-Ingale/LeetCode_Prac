class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Pair each number with its index to retain original order
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numWithIndex.push_back({nums[i], i});
        }

        // Step 2: Use partial sort to get k largest by value
        // Greater comparator sorts in descending order
        partial_sort(numWithIndex.begin(), numWithIndex.begin() + k, numWithIndex.end(),
                     [](const pair<int, int>& a, const pair<int, int>& b) {
                         return a.first > b.first;  // Sort by value descending
                     });

        // Step 3: Take the top k elements and sort them by index to preserve order
        vector<pair<int, int>> topK(numWithIndex.begin(), numWithIndex.begin() + k);
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;  // Sort by original index
        });

        // Step 4: Extract values
        vector<int> result;
        for (const auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
