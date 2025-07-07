class Solution {
public:
    vector<int>buildLPS(string &pattern){
        int n=pattern.length();
        vector<int>lps(n,0);
        int len=0;
        for(int i=1;i<n;){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int>lps=buildLPS(s);
        int len=lps[n-1];
        //// condition: LPS value must be > 0 and string length divisible by pattern length ->means correct
        
        return (len>0 && n%(n-len)==0);
    }
};