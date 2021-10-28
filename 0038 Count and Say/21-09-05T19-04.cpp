class Solution {
public:
    typedef struct pair{
        int num;
        int length;
    }pair;
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        vector<pair> countdata{(pair){1, 1}};
        for(int i = 3; i <= n; i++){
            vector<pair> countdata_copy(countdata);
            countdata.clear();
            int num = countdata_copy[0].length, length = 1;
            if(countdata_copy[0].num == num){
                length++;
            }else{
                countdata.push_back((pair){num, length});
                num = countdata_copy[0].num;
                length = 1;
            }
            for(int i = 1; i < countdata_copy.size(); i++){
                if(countdata_copy[i].length == num){
                    length++;
                }else{
                    countdata.push_back((pair){num, length});
                    num = countdata_copy[i].length;
                    length = 1;
                }
                if(countdata_copy[i].num == num){
                    length++;
                }else{
                    countdata.push_back((pair){num, length});
                    num = countdata_copy[i].num;
                    length = 1;
                }
            }
            countdata.push_back((pair){num, length});
        }
        vector<char> chars;
        for(pair p : countdata){
            chars.push_back(p.length + '0');
            chars.push_back(p.num + '0');
        }
        string s(chars.begin(), chars.end()); 
        return s;
    }
};