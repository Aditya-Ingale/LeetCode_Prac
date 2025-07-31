class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> cur, prev;

        for (int num : arr) {
            cur.clear();
            cur.insert(num);
            for (int x : prev) {
                cur.insert(x | num);
            }
            prev = cur;
            result.insert(cur.begin(), cur.end());
        }

        return result.size();
    }
};
