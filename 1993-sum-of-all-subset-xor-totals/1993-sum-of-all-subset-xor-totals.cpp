class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
private:
    int dfs(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }
        
        // Include current element in XOR or exclude it
        int include = dfs(nums, index + 1, currentXOR ^ nums[index]);
        int exclude = dfs(nums, index + 1, currentXOR);
        
        return include + exclude;
    }
};
