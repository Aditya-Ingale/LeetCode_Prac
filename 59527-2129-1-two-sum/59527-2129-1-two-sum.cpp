class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap; // Stores value and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // The number needed to reach the target
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                // If complement is found, return its index and current index
                return {numIndexMap[complement], i};
            }
            // Otherwise, store the current number with its index
            numIndexMap[nums[i]] = i;
        }
        return {}; // Problem guarantees one solution, so this line won't be reached
    }
};