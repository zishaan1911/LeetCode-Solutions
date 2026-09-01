class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, buy):
            if i >= len(prices):
                return 0  
            return max(
                0 if buy else dfs(i+1, True) - prices[i], # buy
                dfs(i+1, buy), # skip
                0 if not buy else dfs(i+2, False) + prices[i] # sell + cooldown
            )
        return dfs(0, False)   