char rtn_val[2];

char * decodeAtIndex(char * S, int K){
    K -= 1;
    char* s[100];
    long len_tol[100];
    int len_true[100];
    int idx = 0;
    int k = K;
    char* p = S;
    len_tol[0] = 0;
    while(1)
    {
        s[idx] = p;
        while((*p < '2' || *p > '9') && *p != '\0')
        {
            p++;
        }
        len_true[idx] = p - s[idx];
        len_tol[idx] += len_true[idx];
        while(*p >= '2' && *p <= '9')
        {
            len_tol[idx] *= *p - '0';
            p++;
        }
        /*
        printf("%d\n", len_tol[idx]);
        printf("%d\n", len_true[idx]);
        printf("%s\n", s[idx]);
        */
        if(K < len_tol[idx])
        {
            while(1)
            {
                if(idx == 0)
                {
                    k = k % len_true[0];
                    break;
                }
                k = K % (len_tol[idx-1]+len_true[idx]);
                if(k >= len_tol[idx-1])
                {
                    k = (k-len_tol[idx-1]) % len_true[idx];
                    break;
                }
                idx--;
                K = k;
            }
            break;
        }
        len_tol[idx+1] = len_tol[idx];
        idx++;
    }
	rtn_val[0] = *(s[idx]+k);
	rtn_val[1] = '\0';
    return &rtn_val[0];
}