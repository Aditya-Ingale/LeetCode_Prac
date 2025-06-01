class Solution {
public:
    long long distributeCandies(int candies, int limit) {
        // Define a lambda function to calculate combinations of 2 from a given number
        auto calculateComb2 = [](int number) -> long long {
            return static_cast<long long>(number) * (number - 1) / 2;
        };
      
        // If the number of candies is more than triple the limit, no distribution is possible
        if (candies > 3 * limit) {
            return 0;
        }
      
        // Calculate the base number of distributions for n + 2
        long long distributionCount = calculateComb2(candies + 2);
      
        // If there are more candies than the limit, subtract invalid distributions
        if (candies > limit) {
            distributionCount -= 3 * calculateComb2(candies - limit + 1);
        }
      
        // Add back any distributions that were subtracted twice
        if (candies - 2 >= 2 * limit) {
            distributionCount += 3 * calculateComb2(candies - 2 * limit);
        }
      
        // Return the final count of distributions
        return distributionCount;
    }
};
