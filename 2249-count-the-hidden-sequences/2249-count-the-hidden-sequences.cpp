class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minPrefix = 0, maxPrefix = 0, curr = 0;

        for (int diff : differences) {
            curr += diff;
            minPrefix = min(minPrefix, curr);
            maxPrefix = max(maxPrefix, curr);
        }

        long minStart = lower - minPrefix;
        long maxStart = upper - maxPrefix;

        return max(0L, maxStart - minStart + 1);
    }
};
