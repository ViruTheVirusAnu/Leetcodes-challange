class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i = 1;i < prices.size();i++)
        {
            int currentprofit = prices[i] - mini;
            if(currentprofit > profit)
            {
                profit = currentprofit;
            }
            if(prices[i] < mini)
            {
             mini = prices[i];
            }
        }
        return profit;
    }
};