class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0; // Initialize the count of symmetric integers

        // Iterate through each number from low to high (inclusive)
        for (int i = low; i <= high; ++i) {
            if (i >= 10 && i <= 99) {
                int d1 = i / 10; // First digit
                int d2 = i % 10; 

                if (d1 == d2) {
                    count++;
                }
            }
            // --- Check for 4-digit numbers ---
            else if (i >= 1000 && i <= 9999) {
                int d1 = i / 1000;       // First digit
                int d2 = (i / 100) % 10; // Second digit
                int d3 = (i / 10) % 10;  // Third digit
                int d4 = i % 10;
                if (d1 + d2 == d3 + d4) {
                    count++;
                }
            }
        }
        // Return the final count
        return count;
    }
};