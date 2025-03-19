class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size(); vector<int> ans;
        unordered_map<int,int>mp; set<pair<int,int>>st;
        for(auto& it: nums)mp[it]++;
        for(auto& it: mp){
            if(st.size()<k){
                st.insert({it.second, it.first});
            }
            else{
                if(it.second>st.begin()->first){
                    st.erase(st.begin());
                    st.insert({it.second, it.first});
                }
            }
        }
        for(auto & it: st)ans.push_back(it.second);
        return ans;
    }
};