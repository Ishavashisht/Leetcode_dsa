class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        
        if(nums.size()%3!=0)return {};
        sort(nums.begin(),nums.end());
         vector<int> currGroup;
        for(int i=0;i<nums.size();i++){
        currGroup.push_back(nums[i]);
        if(currGroup.size()==3){
            int minElement=currGroup[0];
            int maxElement=currGroup[2];
            if(maxElement-minElement>k){
return {};
            }
            ans.push_back(currGroup);
            currGroup.clear();
        }
        }
        return ans;
    }
};