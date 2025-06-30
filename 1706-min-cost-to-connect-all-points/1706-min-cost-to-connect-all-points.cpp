class Solution {
public:
 
typedef pair<int,int>P;
  int Prims( vector<vector<P>>&adj,int V){
vector<bool>vis(V,false);
priority_queue<P,vector<P>,greater<P>>pq;
pq.push({0,0});

int sum=0;
while(!pq.empty()){
auto p=pq.top();
pq.pop();
int wt=p.first;
int node=p.second;
if(vis[node])continue;
vis[node]=true;
sum+=wt;
for(auto&temp:adj[node]){
    int ngb=temp.first;
    int ngb_wt=temp.second;
    if(!vis[ngb]){
        pq.push({ngb_wt,ngb});
      
    }
}
}
return sum;
  }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<P>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});

            }
        }
        return Prims(adj,V);
    }
};