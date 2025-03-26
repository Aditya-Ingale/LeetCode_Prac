class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (const auto& row : grid) {
            for (int num : row) {
                arr.push_back(num);
            }
        }
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[n / 2];
        int operations = 0;
        
        for (int num : arr) {
            int diff = abs(num - median);
            if (diff % x != 0) return -1; 
            operations += diff / x;
        }
        
        return operations;
    }
};