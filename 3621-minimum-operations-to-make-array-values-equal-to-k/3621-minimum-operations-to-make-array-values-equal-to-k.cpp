class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> distinct_greater;
        for (int num : nums) {
            if (num > k) {
                distinct_greater.insert(num);
            } else if (num < k) {
                return -1; // Impossible if any element is strictly less than k
            }
        }

        return distinct_greater.size();
    }
};