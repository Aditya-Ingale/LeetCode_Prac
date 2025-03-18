class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitwise_or = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); right++) {
        // If new element conflicts, shrink window from left
            while ((bitwise_or & nums[right]) != 0) {
                bitwise_or ^= nums[left];  // Remove nums[left] from the bitmask
                left++;
            }

            bitwise_or |= nums[right]; // Include the new number
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};