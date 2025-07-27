class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int>prev=points[0];
        int count=1;
        for(int i=1;i<points.size();i++){
            int currSP=points[i][0];
            int currEP=points[i][1];
            int prevSP=prev[0];
            int prevEP=prev[1];
            if(currSP>prevEP){
                //no overlap
                count++;
                prev=points[i];
            }
            else{
                prev[0]=max(prevSP,currSP);
                prev[1]=min(prevEP,currEP);

            }
        }
        return count;
    }
};