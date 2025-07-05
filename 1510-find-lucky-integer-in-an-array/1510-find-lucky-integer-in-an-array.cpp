class Solution {
public:
    int findLucky(vector<int>& arr) {
        // Constraint says arr[i] <= 500, so we use a frequency array of size 501
        int freq[501] = {0};

        // Count the frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        // Iterate from high to low to find the largest lucky number
        for (int i = 500; i >= 1; --i) {
            if (freq[i] == i) {
                return i;
            }
        }

        // No lucky number found
        return -1;
    }
};
