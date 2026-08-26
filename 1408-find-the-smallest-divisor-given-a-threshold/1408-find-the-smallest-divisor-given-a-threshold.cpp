class Solution {
public:
 int sumByD(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
         if (nums.size() > threshold) return -1;

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        // Binary search to find smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Try larger divisor
            }
        }

        return low;
    }
        
    
};