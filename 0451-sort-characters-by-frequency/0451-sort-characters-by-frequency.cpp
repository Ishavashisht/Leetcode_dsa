class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
      for (char c : s) {
        mp[c]++;
    } 
       priority_queue<pair<int,char>>pq;

     for(auto&entry:mp)
       { 
        pq.push(make_pair(entry.second,entry.first));
}
string res="";
while(!pq.empty()){
    pair<int,char>p=pq.top();
    pq.pop();
    res.append(p.first,p.second);
}       
return res;
}
    
};