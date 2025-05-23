class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<int> gains;

        for (int x : nums) {
            baseSum += x;
            int gain = (x ^ k) - x;
            gains.push_back(gain);
        }

        // Count how many nodes would benefit from XOR
        int countPos = 0;
        for (int g : gains) {
            if (g > 0) countPos++;
        }

        // If we have even number of positive gain or can make even number of XORs,
        // we apply XOR to all with positive gain.
        // Otherwise, we need to exclude the smallest absolute gain to make the number of operations even.
        if (countPos % 2 == 0) {
            for (int g : gains) {
                if (g > 0) baseSum += g;
            }
        } else {
            int minDiff = INT_MAX;
            for (int g : gains) {
                minDiff = min(minDiff, abs(g));
            }
            for (int g : gains) {
                if (g > 0) baseSum += g;
            }
            baseSum -= minDiff;
        }

        return baseSum;
    }
};
