class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Function to calculate number of distinct prime factors
    int primeScore(int x) {
        int count = 0;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                count++;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) count++; // If x is still > 1, it is a prime factor itself
        return count;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);
        
        for (int i = 0; i < n; i++) {
            scores[i] = primeScore(nums[i]);
        }
        
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        
        // Compute the left boundary of elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && scores[st.top()] < scores[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Compute the right boundary of elements
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && scores[st.top()] <= scores[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        
        // Store elements in a max heap (priority queue)
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
        }
        
        long long result = 1;
        while (k > 0 && !pq.empty()) {
            auto [val, idx] = pq.top(); pq.pop();
            
            long long leftChoices = idx - left[idx];
            long long rightChoices = right[idx] - idx;
            long long count = leftChoices * rightChoices;
            
            long long pick = min((long long)k, count);
            
            result = (result * modPow(val, pick, MOD)) % MOD;
            k -= pick;
        }
        
        return result;
    }
    
    // Function to calculate (base^exp) % mod using fast exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};