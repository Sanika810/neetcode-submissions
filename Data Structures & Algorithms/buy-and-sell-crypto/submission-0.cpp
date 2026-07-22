class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++)
        {
            maxProfit = max(maxProfit , prices[i] - mini);
            mini = min(mini , prices[i]);
        }
        return maxProfit;
    }
};
