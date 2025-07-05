class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int it:nums){
            mp[it]++;
        }
        int goodPairs=0;
        for(auto[val,f]:mp){
            goodPairs+=f*(f-1)/2;
        }
        return goodPairs;
    }
};