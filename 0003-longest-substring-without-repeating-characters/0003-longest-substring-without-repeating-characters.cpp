class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char>mp;
       int left=0,maxLen=0;
       for(int right=0;right<s.length();right++){
        while(mp.count(s[right])){
            mp.erase(s[left]);
            left++;
        }
        mp.insert(s[right]);
        maxLen=max(maxLen,right-left+1);
       } 
       return maxLen;
    }
};