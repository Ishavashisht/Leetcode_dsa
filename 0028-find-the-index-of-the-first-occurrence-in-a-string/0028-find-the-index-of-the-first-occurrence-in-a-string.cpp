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
    int strStr(string haystack, string needle) {
     if(needle.empty())return 0;
      int n=haystack.length();
      int m=needle.length();
      vector<int>lps=buildLPS(needle);
      int i=0,j=0;
      while(i<n){
        if(haystack[i]==needle[j]){
            i++;
            j++;
        
        if(j==m){
            return i-m;
        }
      }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
      }
      return -1;
    }
};