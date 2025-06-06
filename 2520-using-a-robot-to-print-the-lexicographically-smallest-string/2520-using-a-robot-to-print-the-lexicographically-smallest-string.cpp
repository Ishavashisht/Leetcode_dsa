class Solution {
public:
    string robotWithString(string s) {
       int n=s.size();
       int freq[26]={0} ;
       for(char ch:s){
        freq[ch-'a']++;

       }
       string res="";
       stack<char>t;
       for(char ch:s){
        t.push(ch);
        freq[ch-'a']--;
        int minChar=0;
         while (minChar < 26 && freq[minChar] == 0) {
                minChar++;
            }
        while(!t.empty() &&(minChar ==26||t.top()<=('a'+minChar))){
            res+=t.top();
            t.pop();
        }
       }
       return res;
    }
    
};