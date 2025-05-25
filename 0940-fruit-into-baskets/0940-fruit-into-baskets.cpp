class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxlen=0;
        int s=0;
        unordered_map<int,int>mp;
        for(int e=0;e<n;e++){
mp[fruits[e]]++;
while(mp.size()>2){
    mp[fruits[s]]--;
    if(mp[fruits[s]]==0){
        mp.erase(fruits[s]);
    }
    s++;
}
        
maxlen=max(maxlen,e-s+1);
        }
        return maxlen;
    }
};