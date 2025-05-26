class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>>sortIndex;
       for(int i=0;i<nums.size();i++){
        sortIndex.push_back({nums[i],i});
       }
       sort(sortIndex.begin(),sortIndex.end());
       int left=0,right=nums.size()-1;
       while(left<right){
int sum=sortIndex[left].first+sortIndex[right].first;
if(sum<target){
    left++;
}
else if(sum>target){
    right--;
}
else{
    return {sortIndex[left].second,sortIndex[right].second};
}
       }
       return {};
    }
};