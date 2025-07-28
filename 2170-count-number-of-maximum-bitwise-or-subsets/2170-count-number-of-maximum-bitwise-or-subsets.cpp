class Solution {
public:
    int maxOR = 0, count = 0;

    void dfs(vector<int>& nums, int index, int currOR) {
        if (index == nums.size()) {
            if (currOR == maxOR) count++;
            return;
        }

        // Include nums[index]
        dfs(nums, index + 1, currOR | nums[index]);

        // Exclude nums[index]
        dfs(nums, index + 1, currOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOR |= num;  // Compute the maximum OR possible
        }

        dfs(nums, 0, 0);
        return count;
    }
};
