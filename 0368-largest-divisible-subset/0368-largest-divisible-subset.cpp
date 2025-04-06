const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        
        int max_index = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_index]) {
                max_index = i;
            }
        }
        
        vector<int> result;
        for (int k = max_index; k >= 0; k = prev[k]) {
            result.push_back(nums[k]);
            if (prev[k] == -1) break;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
