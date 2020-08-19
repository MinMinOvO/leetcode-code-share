

char * addStrings(char * num1, char * num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1 < len2)
    {
        int tmp = len1;
        len1 = len2;
        len2 = tmp;
        char *tmpc = num1;
        num1 = num2;
        num2 = tmpc;
    }
    int idx1 = len1-1, idx2 = len2-1, idx3=0;
    char *tmp = (char *)malloc((len1+1) * sizeof(char));
    int carry = 0;
    while(idx2 >= 0)
    {
        char next = num1[idx1--] + num2[idx2--] + carry - '0';
        if(next > '9')
        {
            tmp[idx3++] = next - 10;
            carry = 1;
        }
        else
        {
            tmp[idx3++] = next;
            carry = 0;
        }
    }
    //printf("carry: %d\n", carry);
    while(carry > 0 && idx1 >= 0)
    {
        char next = num1[idx1--] + carry;
        if(next > '9')
        {
            tmp[idx3++] = next - 10;
            carry = 1;
        }
        else
        {
            tmp[idx3++] = next;
            carry = 0;
        }
    }
    char *ans;
    if(carry > 0)
    {
        tmp[idx3++] = carry + '0';
        ans = (char *)malloc((idx3+1)*sizeof(char));
    }
    else
    {
        ans = (char *)malloc((idx3+idx1+2)*sizeof(char));
        for(int i = 0; i <= idx1; i++)
        {
            ans[i] = num1[i];
        }
    }
    for(int i=idx1+1, j=idx3-1; j>=0; i++, j--)
    {
        ans[i] = tmp[j];
    }
    ans[idx3+idx1+1] = '\0';
    free(tmp);
    return ans;
}

