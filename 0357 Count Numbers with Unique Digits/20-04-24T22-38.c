

int countNumbersWithUniqueDigits(int n){
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 10;
    }
    if(n >= 11)
    {
        return countNumbersWithUniqueDigits(10);
    }
    int sum = (11 - n) * countNumbersWithUniqueDigits(n-1);
    int i = n - 2;
    while(i >= 0)
    {
        sum +=  countNumbersWithUniqueDigits(i);
        i--;
    }
    return sum;
}

