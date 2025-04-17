class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexMap;
        int count = 0;

        // Store indices for each number
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }

        // Check valid pairs within each group of same numbers
        for (auto& [num, indices] : indexMap) {
            int m = indices.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
