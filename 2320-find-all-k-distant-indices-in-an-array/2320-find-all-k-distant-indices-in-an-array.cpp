class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) keyIndices.push_back(i);
        }

        vector<int> result;
        int j = 0;  // pointer for keyIndices

        for (int i = 0; i < n; ++i) {
            // Move j forward until keyIndices[j] is at least i - k
            while (j < keyIndices.size() && keyIndices[j] < i - k) {
                ++j;
            }
            // If current key index is within distance k
            if (j < keyIndices.size() && abs(keyIndices[j] - i) <= k) {
                result.push_back(i);
            }
        }

        return result;
    }
};
