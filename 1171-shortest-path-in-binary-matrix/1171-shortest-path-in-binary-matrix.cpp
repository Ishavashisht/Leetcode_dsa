class Solution {
public:
   typedef pair<int,pair<int,int>>P;
   vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
        int n=grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>res(n,vector<int>(n,INT_MAX));
        res[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
         int d=pq.top().first;
         pair<int,int> node=pq.top().second;
         int x=node.first;
         int y=node.second;
        pq.pop();
        if (x == n - 1 && y == n - 1)
                return d;
         for(auto dir:directions){
            int new_x=x+dir[0];
            int new_y=y+dir[1];
          int dist=1;
          if(new_x<n && new_x>=0 && new_y<n && new_y>=0 && grid[new_x][new_y]==0 && d+dist<res[new_x][new_y]){
            res[new_x][new_y]=d+dist;
            pq.push({d+dist,{new_x,new_y}});
          }
         }
       }
       return -1;
    }
};