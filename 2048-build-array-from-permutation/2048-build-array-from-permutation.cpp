class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        // Encode both old and new values in each element
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] + (n * (nums[nums[i]] % n));
        }

        // Decode to get the final result
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};
