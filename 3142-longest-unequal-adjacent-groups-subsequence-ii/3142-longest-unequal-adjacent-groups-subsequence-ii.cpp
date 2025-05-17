class Solution {
public:
   bool checkHammmingDis(string &s1,string &s2){
    int diff=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            diff++;
        }
         if(diff>1){
            return false;
        }
    }
    return diff==1;
   }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
     int n=words.size();
     vector<int>dp(n,1);
     vector<int>parent(n,-1);
     int LongestSub=1;
     int LongestSubIdx=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(groups[j]!=groups[i] && words[i].length()==words[j].length() && checkHammmingDis(words[i],words[j])){
                if(dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i]=j;
                    if(LongestSub<dp[i]){
                        LongestSub=dp[i];
                        LongestSubIdx=i;
                    }
                }
            }
        }
     }   
     vector<string>res;
     while(LongestSubIdx!=-1){
        res.push_back(words[LongestSubIdx]);
        LongestSubIdx=parent[LongestSubIdx];
     }
     reverse(begin(res),end(res));
     return res;
    }
};