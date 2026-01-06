class Solution {
public:
vector<int>dijkstra(int src,vector<vector<pair<int,int>>>&adj){
    vector<int> dist(adj.size(), INT_MAX);
     dist[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        pair<int,int>p=pq.top();
        int node=p.second;
        int currdist=p.first;
        pq.pop();
        if(currdist > dist[node]) continue;

        for(auto &nbr:adj[node]){
            int nbrNode=nbr.second;
            int nbrDist=nbr.first;
            if(currdist+nbrDist<dist[nbrNode]){
                dist[nbrNode]=currdist+nbrDist;
                pq.push({dist[nbrNode],nbrNode});
            }
        }
    }
    return dist;

}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using dijkstra algo
        vector<vector<int>> result(n);
      

        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:edges){
            int node1=edge[0];
            int node2=edge[1];
            int wt=edge[2];
            adj[node1].push_back({wt,node2});
            adj[node2].push_back({wt,node1});
        }
        for(int i=0;i<n;i++){
             result[i]=dijkstra(i,adj);
        }

         vector<pair<int,int>>vec;
         for(int i=0;i<n;i++){
            int count=0;
          
            for(int j=0;j<n;j++){
               if(i!=j && result[i][j]<=distanceThreshold){
                  count++;
               }
            }
           vec.push_back({count, i});


         }
         sort(vec.begin(),vec.end(),[](auto &a, auto &b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first < b.first; 
         });
         return vec[0].second;
    }
};