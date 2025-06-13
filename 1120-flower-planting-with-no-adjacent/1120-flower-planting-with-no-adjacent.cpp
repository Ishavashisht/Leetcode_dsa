class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto&path:paths){
            int u=path[0];
            int v=path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>res(n+1,0);
        for(int i=1;i<=n;i++){
            bool used[5]={false};
            for(int ngb:adj[i]){
                int flower=res[ngb];
                if(flower!=0){
                    used[flower]=true;
                }
            }
            for(int type=1;type<=4;type++){
                if(!used[type]){
                    res[i]=type;
                    break;
                }
            }
        }
        return vector<int>(res.begin()+1,res.end());

    }
};