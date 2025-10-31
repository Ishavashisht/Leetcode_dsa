class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
            
            if(mp[x]==2){
                res.push_back(x);
            }
        }
        return res;
    }
};