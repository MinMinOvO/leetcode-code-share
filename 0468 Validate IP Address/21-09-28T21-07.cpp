class Solution {
public:
    bool is_ipv4(string IP){
        int idx=0;
        int val;
        for(int i=0; i<4; ++i){
            if(idx < IP.size() and '0' <= IP[idx] and IP[idx] <= '9'){
                val = IP[idx] - '0';
                idx++;
            }else{
                return false;
            }
            if(idx < IP.size() and '0' <= IP[idx] and IP[idx] <= '9'){
                if(val == 0){
                    return false;
                }
                val = val * 10 + IP[idx] - '0';
                idx++;
            }
            if(idx < IP.size() and '0' <= IP[idx] and IP[idx] <= '9'){
                val = val * 10 + IP[idx] - '0';
                if(val > 255){
                    return false;
                }
                idx++;
            }
            if(i < 3 and (idx >= IP.size() or IP[idx] != '.')){
                return false;
            }
            idx++;
        }
        if(--idx < IP.size()){
            return false;
        }else{
            return true;
        }
        
    }
    bool is_ipv6(string IP){
        int idx = 0;
        int cnt;
        for(int i=0; i<8; i++){
            cnt = 0;
            while(idx < IP.size() and ('0' <= IP[idx] and IP[idx] <= '9' or 
                                      'a' <= IP[idx] and IP[idx] <= 'f' or
                                      'A' <= IP[idx] and IP[idx] <= 'F')){
                idx++;
                if(++cnt > 4){
                    return false;
                }
            }
            if( (i < 7 and (idx >= IP.size() or IP[idx] != ':' ) ) or cnt == 0){
                return false;
            }
            idx++;
        }
        if(--idx < IP.size()){
            return false;
        }else{
            return true;
        }
    }
    string validIPAddress(string IP) {
        if(is_ipv4(IP)){
            return "IPv4";
        }else if(is_ipv6(IP)){
            return "IPv6";
        }else{
            return "Neither";
        }
    }
};