class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool e[101] = {0};  

        int size = nums.size();

        // Traverse the array from the end to the beginning
        for (int i = size - 1; i >= 0; --i) {
            // If the current number was already seen, it's a duplicate
            if (e[nums[i]])
                return (i + 3) / 3;
            // Mark the current number as seen
            e[nums[i]] = true;
        }

        // If we finish the loop without finding duplicates, all elements are unique
        return 0;
    }
};
