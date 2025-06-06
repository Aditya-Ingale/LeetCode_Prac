class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);  // Frequency of each character in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        string t;      // Stack for robot's internal string
        string res;    // Result string to be written on paper
        char minChar = 'a';  // Current minimum character left in s

        for (char c : s) {
            t.push_back(c);
            freq[c - 'a']--;

            // Update minChar to next available character in s
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }

            // Pop from t to res if t.back() <= minChar
            while (!t.empty() && t.back() <= minChar) {
                res.push_back(t.back());
                t.pop_back();
            }
        }

        // Pop remaining characters from t to res
        while (!t.empty()) {
            res.push_back(t.back());
            t.pop_back();
        }

        return res;
    }
};
