

int superPow(int a, int* b, int bSize)
{
    int ans = 1;
    int ms[10];
    ms[0] = 1;
    int c = a % 1337;
    for(int idx_b=bSize-1; idx_b>=0; idx_b--)
    {
        for(int i=1, num=1; i<10; i++)
        {
            num = (c * num) % 1337;
            ms[i] = num;
        }
        c = (ms[9] * c) % 1337;
        ans = (ans * ms[b[idx_b]]) % 1337;
    }
    return ans;
}

