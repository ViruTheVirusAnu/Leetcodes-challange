class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        for(int start = 0; start < n; start++)
        {
            bool sorted = true;

            for(int i = 0; i< n-1;i++)
            {
                int current = nums[(start+i)%n];
                int next = nums[(start + i + 1) % n];

                if(current > next)
                {
                    sorted = false;
                    break;
                }
            }
            if(sorted) return true;
        }
        return false;

    }
};