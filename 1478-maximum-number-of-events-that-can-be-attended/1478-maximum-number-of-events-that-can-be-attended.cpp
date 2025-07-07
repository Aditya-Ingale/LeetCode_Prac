class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; // stores end days
        int day = 0, i = 0, res = 0, n = events.size();

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0];  // jump to the next event's start day
            }

            // Push all events starting on or before 'day'
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i++][1]);
            }

            // Remove events that already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend one event ending the earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
                day++;
            }
        }

        return res;
    }
};
