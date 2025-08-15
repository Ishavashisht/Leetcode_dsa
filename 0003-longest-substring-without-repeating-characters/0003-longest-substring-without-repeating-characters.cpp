class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<s.size()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                maxlen=max(maxlen,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
          
            
        }
        return maxlen;
    }
};