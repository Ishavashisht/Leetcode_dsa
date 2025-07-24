class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int p1=0,p2=0;
        int m=nums1.size(),n=nums2.size();
         sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end());
        while(p1<m && p2<n){
            if(nums1[p1]==nums2[p2]){
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1]<nums2[p2]){
              p1++; 
            }
            else{
                p2++;
            }
        }
        return ans;
    }
};