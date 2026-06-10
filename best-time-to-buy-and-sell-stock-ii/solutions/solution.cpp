class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int totalProfit = 0;

        auto it = prices.begin() + 1;

        while (it != prices.end()) {
            if (*it > *(it-1)) {
                totalProfit += *it - *(it - 1);
            }
            ++it;
        }
        return totalProfit;
    }
};