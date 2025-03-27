class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 1: Find the dominant element
        int dominant = -1, count = 0;
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) {
                dominant = num;
            }
        }

        // Step 2: Check for the valid split
        int leftCount = 0, rightCount = freq[dominant];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
                rightCount--;
            }
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};