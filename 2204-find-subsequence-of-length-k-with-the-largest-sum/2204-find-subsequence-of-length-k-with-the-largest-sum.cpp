class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Min-heap: {value, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (int i = 0; i < nums.size(); ++i) {
            if (minHeap.size() < k) {
                minHeap.push({nums[i], i});
            } else if (nums[i] > minHeap.top().first) {
                minHeap.pop();
                minHeap.push({nums[i], i});
            }
        }

        // Store the k largest elements with original index
        vector<pair<int, int>> topK;
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sort by original index to keep subsequence order
        sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        // Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
