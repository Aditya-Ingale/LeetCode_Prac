class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int num : nums1) {
            if (num == 0) zero1++;
            else sum1 += num;
        }

        for (int num : nums2) {
            if (num == 0) zero2++;
            else sum2 += num;
        }

        long long baseSum1 = sum1 + zero1;
        long long baseSum2 = sum2 + zero2;

        // If it's impossible to increase the smaller side
        if (baseSum1 > baseSum2 && zero2 == 0) return -1;
        if (baseSum2 > baseSum1 && zero1 == 0) return -1;

        // Equal case
        if (baseSum1 == baseSum2) return baseSum1;

        // Otherwise, increase the smaller side by adding required difference
        long long diff = abs(baseSum1 - baseSum2);
        return max(baseSum1, baseSum2);
    }
};
