class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.length()!=t.length())return false;
unordered_map<char,char>map_s_to_t;
unordered_map<char,char>map_t_to_s;
for(int i=0;i<s.length();i++){
char char_s=s[i];
char char_t=t[i];
if(map_s_to_t.count(char_s) && map_s_to_t[char_s]!=char_t){
return false;
}
if(map_t_to_s.count(char_t)&&map_t_to_s[char_t]!=char_s){
return false;}
map_s_to_t[char_s]=char_t;
map_t_to_s[char_t]=char_s;
}
return true;
 
    }
};