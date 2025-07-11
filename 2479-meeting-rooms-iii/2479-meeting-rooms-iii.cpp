class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        // {endTime, room}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> inUse;
        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms
            while (!inUse.empty() && inUse.top().first <= start) {
                available.push(inUse.top().second);
                inUse.pop();
            }

            long long duration = end - start;

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                inUse.emplace(end, room);
                count[room]++;
            } else {
                auto [availableAt, room] = inUse.top();
                inUse.pop();
                inUse.emplace(availableAt + duration, room);
                count[room]++;
            }
        }

        // Find the room with maximum meetings
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) {
                maxRoom = i;
            }
        }

        return maxRoom;
    }
};
