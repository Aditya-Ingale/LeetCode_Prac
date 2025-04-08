class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();

        // Start from the back of the array
        for (int i = n - 1; i >= 0; --i) {
            // If already seen, we must remove more from front
            if (seen.count(nums[i])) {
                // Number of elements before this index (i+1)
                int remaining = i + 1;

                // Number of groups of 3 we need to remove from the start
                return (remaining + 2) / 3;
            }
            seen.insert(nums[i]);
        }

        // If all elements are unique already
        return 0;
    }
};
