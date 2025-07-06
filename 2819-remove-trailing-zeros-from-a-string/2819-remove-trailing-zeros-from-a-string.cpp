class Solution {
public:
    string removeTrailingZeros(string num) {
        int index=num.size()-1;
        while(num[index]=='0'){
            num.pop_back();
            index--;
        }
        return num;
    }
};