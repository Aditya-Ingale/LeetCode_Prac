class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        vector<int> result;

        // Try all 3-digit even numbers
        for (int num = 100; num <= 999; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            // Create a frequency array for this number
            vector<int> currFreq(10, 0);
            currFreq[d1]++;
            currFreq[d2]++;
            currFreq[d3]++;

            // Check if we have enough digits in original freq to make this number
            bool canForm = true;
            for (int i = 0; i < 10; ++i) {
                if (currFreq[i] > freq[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                result.push_back(num);
            }
        }

        return result;
    }
};
