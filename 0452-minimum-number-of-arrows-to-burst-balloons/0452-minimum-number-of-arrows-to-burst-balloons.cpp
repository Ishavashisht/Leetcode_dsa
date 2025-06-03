class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())return 0;
        sort(points.begin(),points.end(),[](const vector<int>&a ,const vector<int>&b){
            return a[1]<b[1];
        });
        int arrow=1;
        int arrowPosition=points[0][1];
        for(auto&ballons:points){
            if(ballons[0]>arrowPosition){
                arrow++;
                arrowPosition=ballons[1];
            }

        }
        return arrow;
    }
};