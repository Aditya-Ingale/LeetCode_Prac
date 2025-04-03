class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        
        int maxLeft = nums[0]; // Maximum value to the left of j
        vector<int> maxRight(n, 0); // Maximum value to the right of j
        
        maxRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }
        
        for (int j = 1; j < n - 1; ++j) {
            long long value = (long long)(maxLeft - nums[j]) * maxRight[j + 1];
            maxVal = max(maxVal, value);
            maxLeft = max(maxLeft, nums[j]);
        }
        
        return maxVal;
    }
};