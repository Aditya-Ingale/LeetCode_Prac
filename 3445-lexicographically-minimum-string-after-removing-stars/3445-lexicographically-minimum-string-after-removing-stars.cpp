class Solution {
public:
    string clearStars(string s) {
        vector<char> stack;
        vector<int> freq(26, 0); // Frequency of characters in stack

        for (char ch : s) {
            if (ch == '*') {
                // Remove the leftmost smallest character
                for (int i = 0; i < 26; ++i) {
                    if (freq[i] > 0) {
                        char smallest = 'a' + i;
                        // Remove from stack (from right to left)
                        for (int j = stack.size() - 1; j >= 0; --j) {
                            if (stack[j] == smallest) {
                                stack.erase(stack.begin() + j);
                                freq[i]--;
                                break;
                            }
                        }
                        break; // Only remove one char for each '*'
                    }
                }
            } else {
                stack.push_back(ch);
                freq[ch - 'a']++;
            }
        }

        return string(stack.begin(), stack.end());
    }
};
