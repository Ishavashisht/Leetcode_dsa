class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>res,sorted;
        for(int i=nums.size()-1 ;i>=0 ;--i){
            auto insert_pos=lower_bound(sorted.begin(),sorted.end(),nums[i]);
            int count=insert_pos-sorted.begin();
            res.push_back(count);
            sorted.insert(insert_pos,nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};