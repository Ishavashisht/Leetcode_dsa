class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
      for(int k=1;k<60;k++){
        long long rem=num1-1LL*k*num2;
        if(rem<0)break;
        int bits=__builtin_popcountll(rem);
        if(bits<=k && k<=rem){
            return k;
        }
      }
        return -1;
    }
};