class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        max_profit = 0
        min_price = prices[0]
        
        for i in range(n):
            if prices[i] < min_price:
                min_price = prices[i]
            
            diff = prices[i] - min_price
            if diff > max_profit:
                max_profit = diff
                
        return max_profit