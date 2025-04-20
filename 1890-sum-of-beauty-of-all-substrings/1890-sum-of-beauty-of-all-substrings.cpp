class Solution {
public:

    int beautySum(string s) {
        int res=0;
     for(int i=0;i<s.size();i++){
           vector<int>freq(26,0);
        for(int j=i;j<s.size();j++){
freq[s[j]-'a']++;
int leastF=INT_MAX;
int mostF=INT_MIN;
for(int k=0;k<26;k++){
     if (freq[k] > 0) {
    mostF=max(mostF,freq[k]);
    leastF=min(leastF,freq[k]);
}
        }
     res+=(mostF-leastF);
    
    }
    }
    return res;
}
};