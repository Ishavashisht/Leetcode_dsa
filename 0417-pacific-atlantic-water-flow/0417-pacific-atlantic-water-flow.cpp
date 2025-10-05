class Solution {
public:
void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>&oceans){
         int m = heights.size();
        int n = heights[0].size();
        if(i>=m||i<0 ||j>=n||j<0 ||oceans[i][j]){
            return;
        }
        oceans[i][j]=true;
        if(i<m-1 && heights[i][j]<=heights[i+1][j]){
            dfs(heights,i+1,j,oceans);
        }//down
        if(i>0 && heights[i][j]<=heights[i-1][j]){
            dfs(heights,i-1,j,oceans);
        }//up
        if(j<n-1 && heights[i][j]<=heights[i][j+1]){
            dfs(heights,i,j+1,oceans);
        }//right
        if(j>0 && heights[i][j]<=heights[i][j-1]){
            dfs(heights,i,j-1,oceans);
        }
      
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
              //pacific top
        for(int i=0;i<n;i++){
            dfs(heights,0,i,pacific);
        }
        //pacific -left
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pacific);
        }
        //atlantic down 
        for(int i=0;i<n;i++){
            dfs(heights,m-1,i, atlantic);
        }
        //atlantic right
        for(int i=0;i<m;i++){
            dfs(heights,i,n-1, atlantic);
        }
        vector<vector<int>>results;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
if(pacific[i][j] &&  atlantic[i][j]){
    results.push_back({i,j});
}
            }
        }
return results;
    }
};