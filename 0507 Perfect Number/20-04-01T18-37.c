#include <math.h>

bool checkPerfectNumber(int num){
    if (num == 1)
    {
        return false;
    }
    int uppbnd = (int)sqrt(num);
    int sum = 1;
    for(int i=2; i<=uppbnd; i++)
    {
        if (i * (num / i) == num)
        {
            if(i != (num/i))
            {
                sum += i + (num / i);
            }
            else
            {
                sum += i;
            }
        }
    }
    return sum == num;
}

