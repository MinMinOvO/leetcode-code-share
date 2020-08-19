

bool isUgly(int num){
    if (num <= 0)
    {
        return 0;
    }
    div_t t;
    while(num > 5)
    {
        t = div(num, 2);
        if(t.rem == 0)
        {
            num = t.quot;
            continue;
        }
        t = div(num, 3);
        if(t.rem == 0)
        {
            num = t.quot;
            continue;
        }
        t = div(num, 5);
        if(t.rem == 0)
        {
            num = t.quot;
            continue;
        }
        return 0;
    }
    return 1;
}

