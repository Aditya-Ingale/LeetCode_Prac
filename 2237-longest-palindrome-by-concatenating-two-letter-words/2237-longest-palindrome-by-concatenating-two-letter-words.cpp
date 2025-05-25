class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }

        int ans = 0;
        bool flag = false;

        for (auto& it : mp) {
            string word = it.first;
            int count = it.second;
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                ans += (count / 2) * 4;
                if (count % 2 == 1) flag = true;
            } else if (mp.find(rev) != mp.end()) {
                int pairs = min(count, mp[rev]);
                ans += pairs * 4;
                mp[rev] = 0; // Avoid double-counting
                mp[word] = 0;
            }
        }

        if (flag) ans += 2; // One word like "gg" can be center

        return ans;
    }
};