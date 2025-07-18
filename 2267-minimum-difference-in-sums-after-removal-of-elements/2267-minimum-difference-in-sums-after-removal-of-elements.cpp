class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();

        // Left to right prefix sums of n smallest
        vector<long long> leftSum(size, 0);
        priority_queue<int> maxHeap;
        long long sumLeft = 0;

        for (int i = 0; i < 2 * n; ++i) {
            maxHeap.push(nums[i]);
            sumLeft += nums[i];
            if (maxHeap.size() > n) {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n)
                leftSum[i] = sumLeft;
        }

        // Right to left suffix sums of n largest
        vector<long long> rightSum(size, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumRight = 0;

        for (int i = size - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            sumRight += nums[i];
            if (minHeap.size() > n) {
                sumRight -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n)
                rightSum[i] = sumRight;
        }

        // Calculate minimum difference
        long long result = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            result = min(result, leftSum[i] - rightSum[i + 1]);
        }

        return result;
    }
};
