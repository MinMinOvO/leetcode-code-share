class Solution {
public:
    string multiply(string num1, string num2) {
        using namespace std;
        list<char> table_n_times_num1[9];
        for(int i=1; i<=9; ++i){
            int carry = 0;
            int val;
            for(int j=num1.size()-1; j>=0; --j){
                val = (num1[j] - '0') * i + carry;
                table_n_times_num1[i-1].push_back(val % 10);
                carry = val / 10;
            }
            while(carry != 0){
                val = carry % 10;
                table_n_times_num1[i-1].push_back(val);
                carry = carry / 10;
            }
        }
        list<char> ans = {0};
        for(int i=0; i<num2.size(); ++i){
            if(num2[i] - '0' != 0){
                list<char> & to_add = table_n_times_num1[num2[i] - '0' - 1];
                int carry = 0;
                auto it1 = ans.begin(), it2 = to_add.begin();
                for(; it1 != ans.end() and it2 != to_add.end(); it1++, it2++){
                    int val = *it1 + *it2 + carry;
                    if(val >= 10){
                        val -= 10;
                        carry = 1;
                    }else{
                        carry = 0;
                    }
                    *it1 = val;
                }
                while(it2 != to_add.end()){
                    int val = *it2 + carry;
                    if(val >= 10){
                        val -= 10;
                        carry = 1;
                    }else{
                        carry = 0;
                    }
                    ans.push_back(val);
                    it2++;
                }
                while(carry != 0){
                    if(it1 != ans.end()){
                        int val = *it1 + carry;
                        if(val >= 10){
                            val -= 10;
                            carry = 1;
                        }else{
                            carry = 0;
                        }
                        *it1 = val;
                        it1++;
                    }else{
                        ans.push_back(carry);
                        break;
                    }
                }
            }
            if(i < num2.size()-1 and (ans.size() > 1 or ans.front() != 0)){
                ans.push_front(0);
            }
        }
        stringstream ss;
        for(auto it = ans.rbegin(); it!=ans.rend(); ++it){
            ss << (char)(*it + '0');
        }
        return ss.str();
    }
};