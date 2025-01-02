class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result; // To store the duplicate numbers
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Map value to index (1-based to 0-based)
            
            if (nums[index] < 0) {
                result.push_back(abs(nums[i])); // If negative, it's a duplicate
            } else {
                nums[index] = -nums[index]; // Mark as visited
            }
        }
        
        return result;

    }
};