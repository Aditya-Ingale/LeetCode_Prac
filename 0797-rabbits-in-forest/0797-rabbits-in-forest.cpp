class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int total = 0;

        for (int ans : answers) {
            count[ans]++;
        }

        for (auto [k, v] : count) {
            // Each group has size (k + 1), since answer "k" means there are k other rabbits of same color
            int groupSize = k + 1;
            // Number of such groups needed = ceil(v / groupSize) = (v + groupSize - 1) / groupSize
            int groups = (v + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }

        return total;
    }
};
