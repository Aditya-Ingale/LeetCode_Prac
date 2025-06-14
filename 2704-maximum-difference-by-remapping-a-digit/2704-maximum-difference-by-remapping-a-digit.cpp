class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = num, minVal = num;

        for (char d = '0'; d <= '9'; ++d) {
            // Try max: replace d with '9'
            string maxStr = s;
            for (char& c : maxStr) {
                if (c == d) c = '9';
            }
            maxVal = max(maxVal, stoi(maxStr));

            // Try min: replace d with '0'
            string minStr = s;
            for (char& c : minStr) {
                if (c == d) c = '0';
            }
            minVal = min(minVal, stoi(minStr));
        }

        return maxVal - minVal;
    }
};
