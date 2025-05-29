class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k,int mindays){
        int flowers=0;
        int bouquets=0;
        for(int day:bloomDay){
            if(day<=mindays){
                flowers++;
                if (flowers == k) {
                    bouquets++; // Bouquet formed
                    flowers = 0; // Reset flower count
                }
            
                
            }
            else{
                flowers=0;
            }
            if(bouquets>=m)return true;
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};