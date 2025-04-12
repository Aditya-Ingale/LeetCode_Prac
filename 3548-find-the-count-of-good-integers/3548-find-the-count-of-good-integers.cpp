class Solution {
public:
    using ll = long long;
    unordered_map<int, ll> factorial;

    void precomputeFactorials(int n) {
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = factorial[i - 1] * i;
    }

    string digitSignature(const string& s) {
        vector<int> count(10, 0);
        for (char c : s) count[c - '0']++;
        string key;
        for (int i = 0; i < 10; ++i)
            key += to_string(count[i]) + ",";
        return key;
    }

    // Build palindromes and count digit frequencies of valid k-palindromes
void generateKPalindromes(int n, int k, unordered_map<string, int>& freqCount) {
    int half = (n + 1) / 2;
    int start = pow(10, half - 1);
    int end = pow(10, half);

    for (int i = start; i < end; ++i) {
        string s = to_string(i);
        string rev = s;
        if (n % 2 == 1) rev.pop_back();
        reverse(rev.begin(), rev.end());
        string full = s + rev;

        long long num = stoll(full); // <-- fix here
        if (num % k == 0) {
            freqCount[digitSignature(full)]++;
        }
    }
}

    // Count permutations matching a digit frequency (excluding leading zero)
    ll countPermutations(const string& sig, int n) {
        vector<int> count(10, 0);
        stringstream ss(sig);
        string item;
        int i = 0;
        while (getline(ss, item, ',')) {
            if (!item.empty()) count[i++] = stoi(item);
        }

        ll total = factorial[n];
        for (int c : count)
            total /= factorial[c];

        // Remove permutations with leading zero
        if (count[0] == 0) return total;

        // Now remove those starting with zero
        count[0]--;
        ll invalid = factorial[n - 1];
        for (int c : count)
            invalid /= factorial[c];
        return total - invalid;
    }

    long long countGoodIntegers(int n, int k) {
        precomputeFactorials(n);
        unordered_map<string, int> freqCount;
        generateKPalindromes(n, k, freqCount);

        ll res = 0;
        for (auto& [sig, cnt] : freqCount) {
            res += countPermutations(sig, n);
        }
        return res;
    }
};
