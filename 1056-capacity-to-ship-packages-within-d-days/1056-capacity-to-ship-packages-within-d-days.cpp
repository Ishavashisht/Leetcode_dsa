class Solution {
public:
   bool canship(vector<int>& weights, int days,int capacity){
    int currweight=0;
    int requireddays=1;
    for (int weight : weights) {
    if(currweight+weight>capacity){
        requireddays++;
        currweight=weight;
        if(requireddays>days)return false;
    }
    else {
        currweight+=weight;
    }
    }
    return requireddays<=days;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
        if(canship(weights,days,mid)){
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