class Solution {
public:
    int countSubarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0;
        int n = nums.size();

        for (; right < n; ++right) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int totalDistinct = unique.size();
        return countSubarraysWithKDistinct(nums, totalDistinct) - 
               countSubarraysWithKDistinct(nums, totalDistinct - 1);
    }
};
