class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     unordered_map<int,vector<pair<int,int>>>adj;

      for(auto&edge:times){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
      } 
      vector<int>dist(n+1,INT_MAX);
    dist[k]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
    pq.push({0,k});
    while(!pq.empty()){
        auto[currTime,u]=pq.top();
        pq.pop();
        if(currTime>dist[u])continue;
        for(auto&[ngb,w] :adj[u]){
            if(currTime+w<dist[ngb]){
                dist[ngb]=currTime+w;
                pq.push({dist[ngb],ngb});
            }
        }
    }
    int maxTime=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX)return -1;
        maxTime=max(maxTime,dist[i]);
    }
    return maxTime;
    }
};