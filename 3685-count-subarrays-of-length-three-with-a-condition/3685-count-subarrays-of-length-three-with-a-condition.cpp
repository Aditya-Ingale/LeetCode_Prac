class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i <= nums.size() - 3; ++i) {
            int first = nums[i];
            int middle = nums[i + 1];
            int third = nums[i + 2];

            // Check if middle is divisible by 2 (evenly divisible)
            if (middle % 2 == 0 && (first + third) == (middle / 2)) {
                count++;
            }
        }
        return count;
    }
};
