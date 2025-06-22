class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       
        int n=grid.size();
        int minCount=0;
          if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int,int>>q;   
    q.push({0,0});
    int steps=1;
vector<vector<bool>>vis(n,vector<bool>(n,false));
        vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
       
        while(!q.empty()){
            int size=q.size();
            while(size--){
            auto[x,y]=q.front();
            q.pop();
           if(x==n-1 && y==n-1)return steps;
            for(auto&dir:directions){
                int new_i=x+dir[0];
                int new_j=y+dir[1];
                //pushing the neigbor and increase count 
                if(new_i<n && new_i>=0 && new_j<n && new_j>=0 && grid[x][y]==0 && !vis[new_i][new_j]){
                   vis[new_i][new_j]=true;
                    q.push({new_i,new_j});
                }
            }
            }
            ++steps;
        }
        return -1;
    }
};