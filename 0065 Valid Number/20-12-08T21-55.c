

bool isNumber(char * s){
    char *p = s;
    while(true){
        if(*p == '\0'){
            return false;
        }else if(*p != ' '){
            break;
        }
        ++p;
    }
    if(*p == '-' || *p =='+') ++p;
    if(*p == '.') {
        ++p;
        if(!('0' <= *p && *p <= '9')) return false;
        goto frac;
    }
    if(!('0' <= *p && *p <= '9')) return false;
    ++p;
    while('0' <= *p && *p <= '9'){
        ++p;
    }
    if(*p == '.'){
        frac:
        ++p;
        while('0' <= *p && *p <= '9'){
            ++p;
        }
    }
    if(*p =='e'){
        ++p;
        if(*p == '-' || *p =='+') ++p;
        if(!('0' <= *p && *p <= '9')) return false;
        ++p;
        while('0' <= *p && *p <= '9'){
            ++p;
        }
    }
    while(true){
        if(*p == '\0'){
            return true;
        }else if(*p != ' '){
            return false;
        }
        ++p;
    }
    return false;
}