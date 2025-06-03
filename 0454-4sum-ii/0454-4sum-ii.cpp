class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      if (nums1.empty() || nums2.empty() || nums3.empty() || nums4.empty()) {
    return 0;
}

       unordered_map<int,int>mp;
       int count=0;
       int n=nums1.size();
       for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
    int sum12=nums1[i]+nums2[j];
    mp[sum12]++;
}
       } 
       for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            int currSum=nums3[k]+nums4[l];
int target=-currSum;
            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }
        }
       }
       return count;
    }
};