class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int start = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // start of a new subsequence
            if (nums[i] - nums[start] > k) {
                count++;
                start = i;
            }
        }

        // Count the last group
        return count + 1;
    }
};
