class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0;
        long long pairs = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Increment frequency and update pairs count
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink window from left while we have enough pairs
            while (pairs >= k) {
                res += nums.size() - right; // All subarrays starting from left to right are valid
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};
