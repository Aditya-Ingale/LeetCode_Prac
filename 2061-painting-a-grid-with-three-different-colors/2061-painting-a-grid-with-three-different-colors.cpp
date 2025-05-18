class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Generate all valid states for a column with m rows
    void generateStates(int m, int state = 0, int row = 0, vector<int>& states = *(new vector<int>())) {
        if (row == m) {
            states.push_back(state);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (row == 0 || ((state >> (2 * (row - 1))) & 3) != color) {
                generateStates(m, state | (color << (2 * row)), row + 1, states);
            }
        }
    }

    bool isCompatible(int a, int b, int m) {
        for (int i = 0; i < m; ++i) {
            if (((a >> (2 * i)) & 3) == ((b >> (2 * i)) & 3))
                return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        vector<int> states;
        generateStates(m, 0, 0, states);
        int size = states.size();

        // Precompute valid transitions between states
        vector<vector<int>> transitions(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (isCompatible(states[i], states[j], m)) {
                    transitions[i].push_back(j);
                }
            }
        }

        // DP initialization
        vector<int> dp(size, 1);

        for (int col = 1; col < n; ++col) {
            vector<int> new_dp(size, 0);
            for (int i = 0; i < size; ++i) {
                for (int prev : transitions[i]) {
                    new_dp[i] = (new_dp[i] + dp[prev]) % MOD;
                }
            }
            dp = new_dp;
        }

        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }
        return result;
    }
};
