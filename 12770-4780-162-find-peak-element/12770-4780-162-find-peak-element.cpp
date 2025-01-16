class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Compare mid element with the next element
            if (nums[mid] > nums[mid + 1]) {
                // If nums[mid] > nums[mid + 1], move to the left side (including mid)
                e = mid;
            } else {
                // Otherwise, move to the right side (excluding mid)
                s = mid + 1;
            }
        }

        // At the end of the loop, left == right, which is the peak index
        return s;
    }
};