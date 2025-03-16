using namespace std;

class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank);
            if (totalCars >= cars) return true; // Early exit
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long) (*min_element(ranks.begin(), ranks.end())) * (long long) cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1; // Try smaller time
            } else {
                left = mid + 1;  // Increase time
            }
        }
        return ans;
    }
};