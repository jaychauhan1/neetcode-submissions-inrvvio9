class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // start with the largest possible integer
        int max_profit = 0; // since it's possible to make 0 dollars

        // loop through each day's price
        for(int price : prices){
            // if we sell today, profit would be today's price minus
            // the lowest price we have seen so far 
            int profit = price - min_price;

            max_profit = max(max_profit, profit);// updates max profit whichever one is greater
            min_price = min (min_price, price);
        } 
        return max_profit;        
    }
};
