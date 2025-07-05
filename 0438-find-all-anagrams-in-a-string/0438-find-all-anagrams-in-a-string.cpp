class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int>mp;
        for(char ch:p){
            mp[ch]++;
        }
        int count=mp.size();
int k=p.length();//fixed window size
int i=0,j=0;
vector<int>ans;
while(j<s.length()){
    if(mp.count(s[j])){
        mp[s[j]]--;
        if(mp[s[j]]==0){
            count--;
        }
    }
    if(j-i+1<k){
        j++;
    }
    else if(j-i+1==k){
        //valid window
        if(count==0){
            ans.push_back(i);
        }
        if(mp.count(s[i])){
            if(mp[s[i]]==0){
                count++;
            }
            mp[s[i]]++;
        }
i++;
j++;

    }
}
return ans;
    }
};