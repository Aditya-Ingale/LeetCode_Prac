class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        
        // Pad the string if it's not a multiple of k
        int remainder = n % k;
        if (remainder != 0) {
            s.append(k - remainder, fill);
        }

        // Divide the string into groups of k characters
        for (int i = 0; i < s.size(); i += k) {
            result.push_back(s.substr(i, k));
        }

        return result;
    }
};
