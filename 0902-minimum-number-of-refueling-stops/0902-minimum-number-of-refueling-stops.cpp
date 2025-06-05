class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int stops=0;
      int prevPosition=0;
      int fuel=startFuel;
      priority_queue<int>pq;
      for(int i=0;i<=stations.size();i++){
        int currPos=(i==stations.size())?target:stations[i][0];
        int dist=currPos-prevPosition;
        fuel-=dist;
        while(fuel<0 && !pq.empty()){
            fuel+=pq.top();
            pq.pop();
            stops++;

        }
        if(fuel<0)return -1;
        if(i<stations.size())pq.push(stations[i][1]);
        prevPosition=currPos;
      }  
      return stops;
    }
};