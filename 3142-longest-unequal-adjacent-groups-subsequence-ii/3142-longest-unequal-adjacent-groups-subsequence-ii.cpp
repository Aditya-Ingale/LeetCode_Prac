using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        if (n == 0) {
            return {};
        }

        vector<string> longest_subsequence;
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        auto hamming_distance = [&](const string& s1, const string& s2) {
            if (s1.length() != s2.length()) {
                return -1; // Indicate unequal length
            }
            int dist = 0;
            for (size_t i = 0; i < s1.length(); ++i) {
                if (s1[i] != s2[i]) {
                    dist++;
                }
            }
            return dist;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && words[i].length() == words[j].length() && hamming_distance(words[i], words[j]) == 1) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        int max_len = 0;
        int end_index = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                end_index = i;
            }
        }

        if (end_index != -1) {
            int curr = end_index;
            while (curr != -1) {
                longest_subsequence.push_back(words[curr]);
                curr = parent[curr];
            }
            reverse(longest_subsequence.begin(), longest_subsequence.end());
        } else if (n > 0) {
            return {words[0]};
        }

        return longest_subsequence;
    }
};