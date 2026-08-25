class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int bouquets = 0;
        int count = 0;

        for (int flower : bloomDay) {

            if (flower <= day) {
                count++;

                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            }
            else {
                count = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // Need m*k flowers
        if ((long long)m * k > n)
            return -1;

        int low = *min_element(
            bloomDay.begin(),
            bloomDay.end()
        );

        int high = *max_element(
            bloomDay.begin(),
            bloomDay.end()
        );

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {

                // mid works
                // Try an earlier day
                high = mid - 1;
            }
            else {

                // mid doesn't work
                // Need more days
                low = mid + 1;
            }
        }

        return low;
    }
};