class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    
    for(int i = 0; i <= n - 3; i++) {  // Ensure there are 3 elements left
        if(nums[i] == 0) {
            ans++;
            // Flip the triplet
            nums[i] = 1 - nums[i];
            nums[i+1] = 1 - nums[i+1];
            nums[i+2] = 1 - nums[i+2];
        }
    }

    // Final check: If there are any remaining zeros, return -1
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) return -1;
    }

    return ans;
    }
};