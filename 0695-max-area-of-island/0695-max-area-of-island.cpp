class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 ||i>=m ||j>=n || grid[i][j]==0 ||vis[i][j]){
            return 0;
        }
            vis[i][j]=true;
            int area=1;
            area+=dfs(grid,vis,i-1,j);
            area+=dfs(grid,vis,i+1,j);
            area+=dfs(grid,vis,i,j-1);
            area+=dfs(grid,vis,i,j+1);
            return area;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    // if(grid.size()==0)return 0;
     int m=grid.size();
     int n=grid[0].size();
     int maxArea=0;
     vector<vector<bool>>vis(m,vector<bool>(n,false));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
               maxArea=max(maxArea,dfs(grid,vis,i,j));
            }
        }
     }  
     return maxArea;

    }
};