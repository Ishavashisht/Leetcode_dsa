class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string res="";
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string candidate=number.substr(0,i)+number.substr(i+1);
           res=max(res,candidate);
            }

        }
        return res;
    }
};