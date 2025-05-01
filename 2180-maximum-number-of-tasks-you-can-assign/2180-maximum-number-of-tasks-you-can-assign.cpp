class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        int usedPills = 0;
        
        for (int i = k - 1; i >= 0; --i) {
            int taskStrength = tasks[i];
            
            // Try assigning without pill
            auto it = available.lower_bound(taskStrength);
            if (it != available.end()) {
                available.erase(it);
            }
            else {
                // Try assigning with pill
                it = available.lower_bound(taskStrength - strength);
                if (it == available.end() || usedPills == pills)
                    return false;
                ++usedPills;
                available.erase(it);
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
