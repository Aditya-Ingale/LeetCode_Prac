class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // If any number in nums is less than k, impossible
        for (int num : nums) {
            if (num < k) return -1;
        }

        set<int> greaterValues;  // store unique values greater than k
        for (int num : nums) {
            if (num > k) {
                greaterValues.insert(num);
            }
        }

        return greaterValues.size(); // each unique value needs one operation
    }
};
