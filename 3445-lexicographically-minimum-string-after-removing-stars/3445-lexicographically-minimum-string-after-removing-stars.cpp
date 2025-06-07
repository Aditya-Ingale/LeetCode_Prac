class Solution {
public:
    string clearStars(string s) {
        vector<char> stk;

        for (char ch : s) {
            if (ch == '*') {
                // Find index of smallest character from right to left
                int minIndex = -1;
                char minChar = 'z' + 1;

                // Find the smallest character in the stack
                for (int i = stk.size() - 1; i >= 0; --i) {
                    if (stk[i] != '*') {
                        if (stk[i] < minChar) {
                            minChar = stk[i];
                            minIndex = i;
                        }
                    }
                }

                if (minIndex != -1) {
                    stk.erase(stk.begin() + minIndex);
                }
            } else {
                stk.push_back(ch);
            }
        }

        return string(stk.begin(), stk.end());
    }
};
