class Solution {
public:
    string addBinary(string a, string b) {
         string result = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        // Traverse both strings from the end
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            result += (sum % 2) + '0'; // Add the current bit to the result
            carry = sum / 2; // Update carry
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct order
        return result;
    }
};