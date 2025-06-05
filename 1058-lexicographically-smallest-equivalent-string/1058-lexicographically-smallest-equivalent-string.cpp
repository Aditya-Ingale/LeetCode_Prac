class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        // Always keep the lex smaller char as parent
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        // Union the equivalent characters
        for (int i = 0; i < s1.size(); ++i)
            unite(s1[i] - 'a', s2[i] - 'a');

        // Build result using the smallest lex representative
        string result;
        for (char c : baseStr)
            result += char(find(c - 'a') + 'a');

        return result;
    }
};
