

int divide(int dividend, int divisor){
    long _divisor = divisor < 0? (-(long)divisor) << 31 : (long)divisor << 31;
    long _dividend = dividend < 0? -(long)dividend : (long)dividend;
    uint ans = 0;
    for(int i=0; i<32; i++){
        if(_dividend >= _divisor){
            ans = (ans << 1) | 1;
            _dividend = _dividend - _divisor;
        } else {
            ans = ans << 1;
        }
        _divisor = _divisor >> 1;
    }
    if(ans == 0x80000000 && divisor == -1) 
        return 0x7fffffff;
    else 
        return (dividend ^ divisor) >= 0? ans : -ans;
}