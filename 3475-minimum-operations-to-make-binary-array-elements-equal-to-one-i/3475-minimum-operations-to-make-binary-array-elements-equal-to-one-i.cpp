class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int operations = 0;

    for (int i = 0; i <= n - 3; i++) {
        if (nums[i] == 0) {
            // Flip nums[i], nums[i+1], nums[i+2]
            nums[i] ^= 1;
            nums[i+1] ^= 1;
            nums[i+2] ^= 1;
            operations++;
        }
    }

    // Check if the array is fully converted to all 1s
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            return -1;  // Impossible case
        }
    }

    return operations;       
    }
};