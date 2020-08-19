

int maxProfit(int* prices, int pricesSize){
    long max = -1742565357;
    long profit = 0;
    for(int i = pricesSize-1; i >= 0; i--)
    {
        long num = (long)prices[i];
        if(max - num > profit)
        {
            profit = max - num;
        }
        else if(max < num)
        {
            max = num;
        }
    }
    if(profit < 0)
    {
        profit = 0;
    }
    return (int)profit;
}

