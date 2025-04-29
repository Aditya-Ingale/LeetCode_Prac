class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long result = 0;

        int count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) count++;

            while (count >= k) {
                // Valid subarrays: [left, right], [left+1, right], ..., [right, right]
                result += (n - right);
                if (nums[left] == maxVal) count--;
                left++;
            }
        }

        return result;
    }
};
