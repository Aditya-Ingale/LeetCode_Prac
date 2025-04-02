class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        
        int maxLeft = nums[0]; // Maximum value of nums[i] seen so far
        vector<int> maxRight(n, 0); // maxRight[k] stores the maximum nums[k] for k > j
        
        // Compute maxRight[k] in reverse order
        maxRight[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; k--) {
            maxRight[k] = max(maxRight[k + 1], nums[k]);
        }
        
        // Iterate through j as the middle element
        for (int j = 1; j < n - 1; j++) {
            if (maxLeft > nums[j] && maxRight[j + 1] > 0) {
                maxVal = max(maxVal, (long long)(maxLeft - nums[j]) * maxRight[j + 1]);
            }
            maxLeft = max(maxLeft, nums[j]); // Update maxLeft
        }
        
        return maxVal;
    }
};