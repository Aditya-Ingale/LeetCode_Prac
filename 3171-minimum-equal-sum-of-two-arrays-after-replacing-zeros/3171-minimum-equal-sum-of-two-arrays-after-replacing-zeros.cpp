class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int num : nums1) {
            if (num == 0) zeros1++;
            else sum1 += num;
        }

        for (int num : nums2) {
            if (num == 0) zeros2++;
            else sum2 += num;
        }

        long long baseSum1 = sum1 + zeros1;
        long long baseSum2 = sum2 + zeros2;

        // If it's impossible (no zero to adjust on the smaller side)
        if (baseSum1 > baseSum2 && zeros2 == 0) return -1;
        if (baseSum2 > baseSum1 && zeros1 == 0) return -1;

        // Minimum equal sum is the maximum of both base sums (after filling 0s with 1s)
        return max(baseSum1, baseSum2);
    }
};
