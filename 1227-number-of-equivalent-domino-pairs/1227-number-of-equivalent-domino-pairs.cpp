class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;

        for (const auto& d : dominoes) {
            // Normalize the domino: [a, b] -> [min(a, b), max(a, b)]
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            result += count[key]; // Add current count to result (pairs already seen)
            count[key]++;         // Increment count for this key
        }

        return result;
    }
};
