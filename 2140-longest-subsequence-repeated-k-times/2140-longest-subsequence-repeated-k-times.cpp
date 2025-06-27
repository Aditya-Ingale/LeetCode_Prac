#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Solution {
 public:
  std::string longestSubsequenceRepeatedK(const std::string& s, int k) {
    std::string ans;
    std::vector<int> count(26);
    std::vector<char> possibleChars;
    std::queue<std::string> q{{""}};

    for (const char c : s)
      ++count[c - 'a'];

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c - 'a'] >= k)
        possibleChars.push_back(c);

    while (!q.empty()) {
      const std::string currSubseq = q.front();
      q.pop();
      if (currSubseq.length() * k > s.length())
        return ans;
      for (const char c : possibleChars) {
        const std::string& newSubseq = currSubseq + c;
        if (isSubsequence(newSubseq, s, k)) {
          q.push(newSubseq);
          ans = newSubseq;
        }
      }
    }

    return ans;
  }

 private:
  bool isSubsequence(const std::string& subseq, const std::string& s, int k) {
    int i = 0;
    for (const char c : s)
      if (c == subseq[i])
        if (++i == subseq.length()) {
          if (--k == 0)
            return true;
          i = 0;
        }
    return false;
  }
};