class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--; // we start from 1, so k--

        while (k > 0) {
            long steps = calcSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Skip this subtree
                curr++;
                k -= steps;
            } else {
                // Go deeper in this subtree
                curr *= 10;
                k--;
            }
        }

        return (int)curr;
    }

private:
    long calcSteps(long n, long curr, long next) {
        long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
