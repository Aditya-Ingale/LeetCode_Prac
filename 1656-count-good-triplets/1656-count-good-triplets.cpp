class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int abs_ij = abs(arr[i] - arr[j]);
                if (abs_ij > a) continue;  // prune early

                for (int k = j + 1; k < n; ++k) {
                    int abs_jk = abs(arr[j] - arr[k]);
                    if (abs_jk > b) continue; // prune early
                    int abs_ik = abs(arr[i] - arr[k]);
                    if (abs_ik > c) continue; // prune early

                    count++;
                }
            }
        }

        return count;
    }
};
