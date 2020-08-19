

int getSum(int a, int b){
    unsigned int c = a ^ b;
    unsigned int carry = (unsigned int)(a & b) << 1;
    unsigned int d = c;
    while(carry != 0)
    {
        c = d ^ carry;
        carry = (d & carry) << 1;
        d = c;
    }
    return (int)c;
}

