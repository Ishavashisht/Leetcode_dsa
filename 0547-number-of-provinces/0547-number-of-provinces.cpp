class Solution {
public:
   void dfs(vector<vector<int>>& isConnected,int i,vector<bool>&vis){
     int n=isConnected.size();
     vis[i]=true;
   for (int neighbor = 0; neighbor < n; ++neighbor) {
    if (isConnected[i][neighbor] == 1 && !vis[neighbor]) {
        dfs(isConnected, neighbor, vis);
    }
}

   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
           
                if(!vis[i]){
                    dfs(isConnected,i,vis);
                    count++;
                }
            
        }
        return count;
    }
};