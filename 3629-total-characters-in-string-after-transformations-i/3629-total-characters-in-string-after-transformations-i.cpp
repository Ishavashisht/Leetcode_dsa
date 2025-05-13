class Solution {
public:
const int MOD=1e9+7;
    int lengthAfterTransformations(string s, int t) {
     vector<long long>freq(26,0);
        for(char ch:s){
          
        freq[ch-'a']++;

        }
        while(t-->0){
            vector<long long>newf(26);
            for(int i=0;i<25;i++){
                
                newf[i+1]=freq[i];
            }
              
               newf[0]=(newf[0]+freq[25])%MOD;
                newf[1]=(newf[1]+freq[25])%MOD;
   freq=newf; 
                }
        
        long long count=0;
        for(int i=0;i<26;i++){
            count=(count+freq[i])%MOD;
        }
        return count;
    }
};