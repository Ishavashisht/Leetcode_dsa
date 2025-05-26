class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,w=nums.size()-1;
            
            while(k<w){
            long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[w];
         
if(sum<target){
    
    k++;
}
else if(sum>target){
    w--;
}
else {
    ans.push_back({nums[i],nums[j],nums[k],nums[w]});


while(k<w && nums[k]==nums[k+1])k++;
while(k<w && nums[w]==nums[w-1])w--;

k++;
w--;
            }
            }
        }
}
        return ans;
    }
};