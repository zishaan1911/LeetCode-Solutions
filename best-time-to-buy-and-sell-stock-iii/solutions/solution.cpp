class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto firstBuy = INT_MIN;
        auto firstSell = 0;
        auto secondBuy = INT_MIN;
        auto secondSell = 0;

        for (auto it = prices.begin(); it != prices.end(); ++it) {
            int price = *it;

            firstBuy = max(firstBuy, -price);
            firstSell = max(firstSell, firstBuy + price);

            secondBuy = max(secondBuy, firstSell - price);
            secondSell = max(secondSell, secondBuy + price);
        }

        return secondSell;
    }
};