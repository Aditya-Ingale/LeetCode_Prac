class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Base cases
        
        //Binary Search
        int left = 1, right = x, result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // To avoid overflow, use mid <= x / mid instead of mid * mid <= x
            if (mid <= x / mid) {
                result = mid; // Update result to current mid
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        
        return result;
    }
};