#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = std::max(buy[j], sell[j - 1] - price);
                sell[j] = std::max(sell[j], buy[j] + price);
            }
        }

        return sell[k];
    }
};