class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> result;
        
        // Step 1: Store the last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        // Step 2: Traverse and partition
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end) { // Found a partition
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};