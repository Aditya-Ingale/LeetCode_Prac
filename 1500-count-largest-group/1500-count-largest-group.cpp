class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            groupCount[sum]++;
            maxSize = max(maxSize, groupCount[sum]);
        }

        int result = 0;
        for (const auto& pair : groupCount) {
            if (pair.second == maxSize) {
                result++;
            }
        }

        return result;
    }
};
