class Solution {
public:
    bool caneatall(vector<int>&piles,int h,int k){
        int time=0;
        for(auto p:piles){
          time += (p + k - 1) / k; // This is equivalent to ceil(p / k)

             if (time > h) return false;

        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(caneatall(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};