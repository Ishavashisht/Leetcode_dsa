class Solution {
public:
vector<int>dirX={-1,1,0,0};
vector<int>dirY={0,0,-1,1};
bool isValid(int x,int y,int n){
return x>=0 && x<n && y>=0 && y<n;
}

    int swimInWater(vector<vector<int>>& grid) {
      int n=grid.size();
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
vector<vector<bool>>visited(n,vector<bool>(n,false));
minHeap.push({grid[0][0],0,0});
visited[0][0]=true;
int maxElevation=0;
while(!minHeap.empty()){
auto curr=minHeap.top();
minHeap.pop();
int elevation=curr[0];
int x=curr[1];
int y=curr[2];
maxElevation=max(maxElevation,elevation);
if(x==n-1 && y==n-1){
return maxElevation;
}
for(int i=0;i<4;i++){
int newX=x+dirX[i];
int newY=y+dirY[i];
if(isValid(newX,newY,n) && !visited[newX][newY]){
visited[newX][newY]=true;
minHeap.push({grid[newX][newY],newX,newY});
}
}
}
return -1;
  
    }
};