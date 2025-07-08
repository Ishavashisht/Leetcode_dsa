class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen=0;
        for(int i=1;i<=26;i++){
            unordered_map<char,int>freq;
            int left=0,right=0;
            int unique=0,countAtleastK=0;
            while(right<s.size()){
                if(unique<=i){
                    char ch=s[right];
                    if(freq[ch]==0)unique++;
                    freq[ch]++;
                    if(freq[ch]==k)countAtleastK++;
                    right++;
                }
                else{
                    char ch=s[left];
                     if (freq[ch] == k) countAtleastK--;
                freq[ch]--;
                if (freq[ch] == 0) unique--;
                left++;
            }
            if(unique==i && unique==countAtleastK){
                maxLen=max(maxLen,right-left);
            }
                }
                }
                return maxLen;
            }
      
};