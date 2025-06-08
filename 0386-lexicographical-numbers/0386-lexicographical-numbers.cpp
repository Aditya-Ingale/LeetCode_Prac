class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10; // go deeper (e.g., 1 → 10)
            } else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10; // backtrack
                }
                curr += 1; // move to next sibling
            }
        }
        return result;
    }
};
