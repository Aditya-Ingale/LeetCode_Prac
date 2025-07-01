class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1; // Original word without any deletion
        
        for (int i = 0; i < n;) {
            int j = i;
            // Find the end of the current character group
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int len = j - i;
            if (len > 1) {
                count += (len - 1); // Add (len - 1) possible deletions
            }
            i = j;
        }

        return count;
    }
};
