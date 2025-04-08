class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = n / 3 + (n % 3 != 0); // maximum possible operations
        for (int i = 0; i <= n; i += 3) {
            unordered_set<int> seen;
            bool allUnique = true;
            for (int j = i; j < n; ++j) {
                if (seen.count(nums[j])) {
                    allUnique = false;
                    break;
                }
                seen.insert(nums[j]);
            }
            if (allUnique) {
                minOps = min(minOps, i / 3);
            }
        }
        return minOps;
    }
};
