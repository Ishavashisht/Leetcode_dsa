class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<int,int>mp;
        
       for(auto ch:s){
        mp[ch]++;
       } 
       if(mp.size()<=k){
        return 0;

       }
       vector<int>freq;
       for(auto it:mp){
        freq.push_back(it.second);
       }
       sort(freq.begin(),freq.end());
       int del=0;
       int excess=mp.size()-k;
       for(int i=0;i<excess;i++){
        del+=freq[i];
       }
       return del;
       
    }
};