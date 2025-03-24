class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings by start day
        sort(meetings.begin(), meetings.end());

        int freeDays = 0, lastEnd = 0;

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Count free days between the last meeting and the current one
            if (start > lastEnd + 1) {
                freeDays += (start - lastEnd - 1);
            }

            // Extend lastEnd if current meeting ends later
            lastEnd = max(lastEnd, end);
        }

        // Count free days after the last meeting
        if (lastEnd < days) {
            freeDays += (days - lastEnd);
        }

        return freeDays;
    }
};