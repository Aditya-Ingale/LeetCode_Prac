class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        /*
        for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            if (it->second % 2 != 0) {
                return false;  // If any count is odd, return false
            }
        }
        */

        // Check if all frequencies are even
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }

        

        return true;
    }
};