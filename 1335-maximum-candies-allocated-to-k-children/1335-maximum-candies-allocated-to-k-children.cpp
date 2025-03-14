class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int result = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            // Count how many children can get 'mid' candies
            for (int c : candies) {
                count += c / mid;
            }
            
            if (count >= k) {  // If we can serve at least k children
                result = mid;   // Store possible answer
                low = mid + 1;  // Try for a bigger size
            } else {
                high = mid - 1; // Try a smaller size
            }
        }
        return result;
    }
};