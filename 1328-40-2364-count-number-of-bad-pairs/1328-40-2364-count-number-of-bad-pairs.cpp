class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long bad_pairs = 0;
        std::unordered_map<long long, long long> count_map;
        
        // Traverse through the array
        for (int i = 0; i < nums.size(); ++i) {
            long long diff = i - nums[i];  // Calculate i - nums[i]
            
            // Add to bad_pairs the number of good pairs formed by this diff
            bad_pairs += i - count_map[diff];
            
            // Increment the count of the current diff
            count_map[diff]++;
        }
        
        return bad_pairs;
    }
};