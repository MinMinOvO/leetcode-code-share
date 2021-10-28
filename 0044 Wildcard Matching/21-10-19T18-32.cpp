class Solution {
public:
    int *dp;
    size_t dp_row_size;
    std::string::iterator it_s_begin, it_p_begin, it_s_end, it_p_end;
    bool bfs(std::string::iterator it_s, std::string::iterator it_p, std::string::iterator const & itend_s, std::string::iterator const & itend_p){
        if(it_s == itend_s){
            while(it_p != itend_p and *it_p == '*'){
                it_p++;
            }
            return it_p == itend_p;
        }
        if(it_p == itend_p){
            return it_s == itend_s;
        }
        if(dp[(it_s - it_s_begin) * dp_row_size + (it_p - it_p_begin)]){
            return bool((dp[(it_s - it_s_begin) * dp_row_size + (it_p - it_p_begin)]) - 1);
        }
        bool ans;
        if(*it_p == '?'){
            it_s += 1;
            it_p += 1;
            ans = bfs(it_s, it_p, itend_s, itend_p);
            goto rtn;
        }else if(*it_p == '*'){
            it_p += 1;
            ans = bfs(it_s, it_p, itend_s, itend_p);
            if(ans) goto rtn;
            it_p -= 1;
            it_s += 1;
            ans = bfs(it_s, it_p, itend_s, itend_p);
            goto rtn;
        }else if(*it_p == *it_s){
            it_p += 1;
            it_s += 1;
            ans = bfs(it_s, it_p, itend_s, itend_p);
        }else{
            ans = false;
            goto rtn;
        }
        rtn:
        if(it_s < itend_s and it_p < itend_p){
            dp[(it_s - it_s_begin) * dp_row_size + (it_p - it_p_begin)] = 1 + int(ans);
        }
        return ans;
    }

    bool isMatch(std::string s, std::string p) {
        dp = new int[s.size() * p.size()]();
        dp_row_size = p.size();
        it_s_begin = s.begin();
        it_p_begin = p.begin();
        auto it_s = s.begin();
        auto it_p = p.begin();
        return bfs(it_s, it_p, s.end(), p.end());
    }
};