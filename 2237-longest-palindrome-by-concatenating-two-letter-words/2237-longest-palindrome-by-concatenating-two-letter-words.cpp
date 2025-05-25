class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int length = 0;
        bool hasMiddle = false;

        for (const string& word : words) {
            string reversed = string(word.rbegin(), word.rend());
            if (wordCount[reversed] > 0) {
                // Found a reverse pair, add 4 to length (2 chars each word)
                length += 4;
                wordCount[reversed]--;
            } else {
                wordCount[word]++;
            }
        }

        // Check for any word like "gg" which can be placed in the middle
        for (auto& [word, count] : wordCount) {
            if (word[0] == word[1] && count > 0) {
                length += 2;
                break;
            }
        }

        return length;
    }
};
