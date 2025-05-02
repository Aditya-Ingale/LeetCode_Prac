class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string res = dominoes;
        int left = 0;

        while (left < n) {
            // Find the next non-dot character
            int right = left;
            while (right < n && res[right] == '.') right++;

            char leftChar = (left == 0) ? 'L' : res[left - 1];
            char rightChar = (right == n) ? 'R' : res[right];

            if (leftChar == rightChar) {
                // Same direction, fill all with that
                for (int k = left; k < right; ++k)
                    res[k] = leftChar;
            } else if (leftChar == 'R' && rightChar == 'L') {
                // Opposite directions, fill inward
                int l = left, r = right - 1;
                while (l < r) {
                    res[l++] = 'R';
                    res[r--] = 'L';
                }
                // center remains '.' if l == r
            }
            // Else (L...R), do nothing

            left = right + 1;
        }

        return res;
    }
};
