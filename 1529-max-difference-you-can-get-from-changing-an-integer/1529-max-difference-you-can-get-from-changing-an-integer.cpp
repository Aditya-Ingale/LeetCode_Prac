class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string max_s = s, min_s = s;

        // Build max_s by replacing the first non-9 digit with 9
        char to_replace_max = 0;
        for (char c : s) {
            if (c != '9') {
                to_replace_max = c;
                break;
            }
        }
        if (to_replace_max != 0) {
            for (char &c : max_s) {
                if (c == to_replace_max) c = '9';
            }
        }

        // Build min_s
        char to_replace_min = 0, replace_with = 0;
        if (s[0] != '1') {
            to_replace_min = s[0];
            replace_with = '1';
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    to_replace_min = s[i];
                    replace_with = '0';
                    break;
                }
            }
        }
        if (to_replace_min != 0) {
            for (char &c : min_s) {
                if (c == to_replace_min) c = replace_with;
            }
        }

        int max_val = stoi(max_s);
        int min_val = stoi(min_s);
        return max_val - min_val;
    }
};
