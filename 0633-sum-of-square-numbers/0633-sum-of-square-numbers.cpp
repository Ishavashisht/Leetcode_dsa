class Solution {
public:
    bool judgeSquareSum(int c) {
      long long a=0,b=sqrt(c);
      while(a<=b){
        long long sum=a*a+b*b;
        if(sum==c){
            return true;

        }
        if(sum<c){
            a++;
        }
        else{
            b--;
        }
      }
        return false;
    }
};