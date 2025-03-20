class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>mp;
        set<pair<int,int>>st;
        for(auto&it:nums)
            mp[it]++;
            for(auto &x:mp){
                if(st.size()<k){
                    st.insert({x.second,x.first});
                }
                else if(x.second>st.begin()->first){
                    st.erase(st.begin());
                    st.insert({x.second,x.first});
                }
            }
        
        for(auto & it: st)ans.push_back(it.second);
        return ans;
            return ans;
         
    }
};