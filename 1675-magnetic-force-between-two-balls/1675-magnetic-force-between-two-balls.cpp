class Solution {
public:
     bool checkcanbeplace(vector<int>& position, int m,int minforce){
        int count=1;
        int lastPos=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPos>=minforce){
                count++;
                lastPos=position[i];
            
            if(count==m){
                return true;
            }
            }
        }
        return false;
     }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int res=0;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkcanbeplace(position,m,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};