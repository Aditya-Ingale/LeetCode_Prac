class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> lastSeenBit(32, -1);  // Stores latest index where each bit is seen

        for (int i = n - 1; i >= 0; --i) {
            // Update last seen positions of all bits in nums[i]
            for (int bit = 0; bit < 32; ++bit) {
                if (nums[i] & (1 << bit)) {
                    lastSeenBit[bit] = i;
                }
            }

            // Find the furthest bit that must be included
            int furthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeenBit[bit] != -1) {
                    furthest = max(furthest, lastSeenBit[bit]);
                }
            }

            answer[i] = furthest - i + 1;
        }

        return answer;
    }
};
