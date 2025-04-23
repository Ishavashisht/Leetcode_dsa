class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>sums(37);
        for(int i=1;i<=n;i++){
            sums[isdigit(i)]++;
        }  
        int maxi=INT_MIN;
        int count=0;
        for(int i:sums){
            if(i>maxi)maxi=i,count=1;
            else if(i==maxi)count++;
        }
        return count;
    }
        int isdigit(int n){
            int sum=0;
            while(n){
            sum+=n%10;
            n/=10;

        }
        return sum;
          }

};