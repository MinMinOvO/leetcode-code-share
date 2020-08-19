

int smallestRangeI(int* A, int ASize, int K){
    int max = 0xbf3f3f3f;
    int min = 0x3f3f3f3f;
    for(int i=0; i<ASize; i++)
    {
        int num = A[i];
        if(num < min)
        {
            min = num;
        }
        if(num > max)
        {
            max = num;
        }
    }
    long ans = (long)max - (long)min - ((long)K << 1);
    if(ans < 0)
    {
        ans = 0;
    }
    return (int)ans;
}

