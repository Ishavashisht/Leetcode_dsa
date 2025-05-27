class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxLoc=0;
        for(auto&trip:trips){
        maxLoc=max(maxLoc,trip[2]);
    }
 vector<int> passengerChanges(maxLoc + 1, 0);

    for(auto&trip:trips){
        int numPassengers=trip[0];
        int from=trip[1];
        int to=trip[2];
        passengerChanges[from]+=numPassengers;
     passengerChanges[to]-=numPassengers;
    }
    int currPass=0;
    for(int i=0;i<maxLoc;i++){
        currPass+=passengerChanges[i];
        if(currPass>capacity)return false;
    }
    
    return true;
    }
};