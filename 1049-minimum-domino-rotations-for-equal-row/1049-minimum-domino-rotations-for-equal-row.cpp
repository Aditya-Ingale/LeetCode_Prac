class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        // Try both possible values from domino 0
        int res = check(tops[0], tops, bottoms, n);
        if (res != -1) return res;
        return check(bottoms[0], tops, bottoms, n);
    }

private:
    int check(int target, vector<int>& tops, vector<int>& bottoms, int n) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;  // Cannot make all values equal to target
            } else if (tops[i] != target) {
                rotateTop++;  // We need to rotate to bring target to top
            } else if (bottoms[i] != target) {
                rotateBottom++;  // We need to rotate to bring target to bottom
            }
        }
        return min(rotateTop, rotateBottom);
    }
};
