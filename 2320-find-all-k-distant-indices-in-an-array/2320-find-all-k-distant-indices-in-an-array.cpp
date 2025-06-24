class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> isKDist(n, false);  // to mark k-distant indices

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                // mark from max(0, i - k) to min(n - 1, i + k)
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    isKDist[j] = true;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (isKDist[i]) result.push_back(i);
        }

        return result;
    }
};
