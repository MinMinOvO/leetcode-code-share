

bool isPowerOfThree(int n)
{
    if(n == 1)
        return 1;
    if(n <= 0)
        return 0;
    div_t q;
    while(n > 3)
    {
        q = div(n , 3);
        if(q.rem != 0)
        {
            return 0;
        }
        n = q.quot;
    }
    return n%3 == 0;
}

