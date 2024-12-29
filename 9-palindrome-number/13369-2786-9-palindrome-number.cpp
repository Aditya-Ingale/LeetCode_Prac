class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10; // Reverse the last digit
            x /= 10; // Remove the last digit
        }

        // Check if the first half equals the reversed second half
        // For odd-length numbers, ignore the middle digit by dividing reversedHalf by 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};