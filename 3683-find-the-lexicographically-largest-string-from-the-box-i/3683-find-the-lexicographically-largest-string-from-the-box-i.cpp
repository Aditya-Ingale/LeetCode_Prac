class Solution {
public:
    // Method to determine the maximum lexicographical substring
    // that can be formed given the number of friends (numFriends).
    string answerString(string word, int numFriends) {
        // If there is only one friend, return the original word
        if (numFriends == 1) {
            return word;
        }

        int n = word.size(); // Get the length of the input word
        string answer; // Initialize an empty string to store the result

        // Iterate over each character in the word
        for (int i = 0; i < n; ++i) {
            // Determine the maximum length of substring we can extract
            int k = std::min(n - i, n - numFriends + 1);

            // Extract the substring from the current position with length k
            string currentSubstring = word.substr(i, k);

            // Update the answer with the maximum lexicographical substring
            answer = std::max(answer, currentSubstring);
        }

        return answer; // Return the result
    }
};