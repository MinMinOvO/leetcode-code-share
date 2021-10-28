#include <stdlib.h>
#define max(a, b) (a) > (b)? (a) : (b)

int matchX();
int matchY();
char *ps;
int maxlen;

int matchX(){
    if(*ps == '('){
        int len = matchY() + matchX();
        maxlen = max(maxlen, len);
        return len;
    }else{
        return 0;
    }
}//return: Xlen

int matchY(){
    ps += 1;
    int Xlen = matchX();
    if(*ps == ')'){
        ps += 1;
        return Xlen + 2;
    }else{// \0
        return 0;
    }
}//return: Ylen

int longestValidParentheses(char * s){
    // Let Y -> ( X )
    // X -> Y X | \empty
    ps = s;
    maxlen = 0;
    while(*ps != '\0'){
        matchX();
        while(*ps == ')'){
            ps += 1;
        }
    }
    return maxlen;
}
