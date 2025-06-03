class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10)return{};
     unordered_set<string>seen;
unordered_set<string>repeated;
vector<string>res;
for(int i=0;i<=s.length()-10;++i){
string substring=s.substr(i,10);
if(seen.find(substring)!=seen.end()){
repeated.insert(substring);
}
else{
seen.insert(substring);
}
}
res.assign(repeated.begin(),repeated.end());
return res;
   
    }
};