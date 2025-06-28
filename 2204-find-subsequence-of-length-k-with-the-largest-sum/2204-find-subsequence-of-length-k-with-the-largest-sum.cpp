class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> valIndex;

        // Step 1: Store value and original index
        for (int i = 0; i < n; ++i) {
            valIndex.push_back({nums[i], i});
        }

        // Step 2: Sort by value in descending order
        sort(valIndex.begin(), valIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Step 3: Take top k elements (value, index)
        vector<pair<int, int>> topK(valIndex.begin(), valIndex.begin() + k);

        // Step 4: Sort top k elements by original index
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 5: Build the result from sorted indices
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};