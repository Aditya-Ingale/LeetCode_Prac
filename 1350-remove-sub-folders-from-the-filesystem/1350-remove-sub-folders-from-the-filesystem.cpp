class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& path : folder) {
            if (result.empty() || path.compare(0, result.back().length(), result.back()) != 0 || path[result.back().length()] != '/') {
                result.push_back(path);
            }
        }

        return result;
    }
};
